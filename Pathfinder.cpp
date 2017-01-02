#include "Pathfinder.h"

namespace std {
	// When using std::unordered_map<T>, we need to have std::hash<T> or
	// provide a custom hash function in the constructor to unordered_map.
	// Since I'm using std::unordered_map<tuple<int,int>> I'm defining the
	// hash function here. It would be nice if C++ automatically provided
	// the hash function for tuple and pair, like Python does. It would
	// also be nice if C++ provided something like boost::hash_combine. In
	// any case, here's a simple hash function that combines x and y:
	template <>
	struct hash<GameEngine::Point> {
		inline size_t operator()(GameEngine::Point p) const {
			return p.x * 1812433253 + p.y;
		}
	};
}

namespace GameEngine
{
	template<typename T, typename priority_t>
	struct PriorityQueue {
		typedef std::pair<priority_t, T> PQElement;

		//std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> elements;

		inline bool empty() const { return false; }//elements.empty(); }

		inline void put(T item, priority_t priority) {
			//elements.emplace(priority, item);
		}

		inline T get() {
			//T best_item = elements.top().second;
			//elements.pop();
			return T();
		}
	};

	std::vector<Point> reconstruct_path(
		Point start,
		Point goal,
		std::unordered_map<Point, Point>& came_from
	) {
		std::vector<Point> path;
		Point current = goal;
		path.push_back(current);
		while (current != start) {
			current = came_from[current];
			path.push_back(current);
		}
		path.push_back(start); // optional
		std::reverse(path.begin(), path.end());
		return path;
	}

	void a_star_search(const TileMap& graph, const Point& start, const Point& goal,
		std::unordered_map<Point, Point>& came_from, std::unordered_map<Point, double>& cost_so_far);

	std::vector<Point> findPath(World * game_world, const Point& from, const Point& to)
	{
		std::unordered_map<Point, Point> came_from;
		std::unordered_map<Point, double> cost_so_far;
		a_star_search(*game_world->map, from, to, came_from, cost_so_far);
		std::vector<Point> path = reconstruct_path(from, to, came_from);
		return path;
	}

	std::array<Point, 4> getNeighbors(const Point& p) {
		typedef Point P;
		return{ p + P{-1,0}, p + P{1, 0}, p + P{0,-1}, p + P{0, 1} };
	}

	double heuristic(Point a, Point b) {
		return abs(a.x - b.x) + abs(a.y - b.y);
	}

	void a_star_search
	(const TileMap& graph,
		const Point& start,
		const Point& goal,
		std::unordered_map<Point, Point>& came_from,
		std::unordered_map<Point, double>& cost_so_far)
	{
		typedef Point Location;
		PriorityQueue<Location, double> frontier;
		frontier.put(start, 0);

		came_from[start] = start;
		cost_so_far[start] = 0;

		while (!frontier.empty()) {
			auto current = frontier.get();

			if (current == goal) {
				break;
			}

			for (auto next : getNeighbors(current)) {
				double new_cost = cost_so_far[current] + graph.cost(next);
				if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
					cost_so_far[next] = new_cost;
					double priority = new_cost + heuristic(next, goal);
					frontier.put(next, priority);
					came_from[next] = current;
				}
			}
		}
	}
}
