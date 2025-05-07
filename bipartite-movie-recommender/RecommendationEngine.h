#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

// Bipartite graph representation
class RecomendationEngine {
private:
    unordered_map<int, vector<pair<char, int>>> userToMovies; // User -> [(Movie, Rating)]
    unordered_map<char, vector<pair<int, int>>> movieToUsers; // Movie -> [(User, Rating)]

public:
    // Add a rating (edge) to the graph
    // add edge to both userToMovies and movieToUsers
    void addRating(int user, char movie, int rating){
        userToMovies[user].push_back({movie, rating}); // Pushback movie and its rating
        movieToUsers[movie].push_back({user, rating}); // Pushback user and their raiting
    }

    // Recommend movies based on a watched movie
    // see assignment for details
    vector<pair<char, double>> recommend(char watchedMovie) {
        // Map to store scores for each movie
        unordered_map<char, double> movieScores;

        // If watched movie is not in data, return empty list
        if(movieToUsers.find(watchedMovie) == movieToUsers.end()) return {};

        // List of users who rated the watched movie
        const auto& usersRated = movieToUsers[watchedMovie];

        // Iterate through each user who rated the movie
        for(const auto& [user, ratingWatchedMovie] : usersRated) {
            // Get the list of movies rated by this user
            const auto& ratedMovies = userToMovies[user];

            // Iterate through each movie rated
            for(const auto& [movie, ratingOtherMovie] : ratedMovies) {
                // Skip the watched movie
                if(movie == watchedMovie) continue;
                // Calculate contribution to movie's score
                double contribution = ratingWatchedMovie * ratingOtherMovie;

                // Accumulate contribution to movie's total score
                movieScores[movie] += contribution;
            }
        }
        // Convert map to a sorted by scores vector descending
        vector<pair<char, double>> recommendations(movieScores.begin(), movieScores.end());
        sort(recommendations.begin(), recommendations.end(),
            [](const pair<char, double>& a, const pair<char, double>& b){
                return a.second > b.second; // In descending order
            });
        return recommendations;
    }
    // Print the graph
    void printGraph() {
        cout << "User -> Movies:" << endl;
        for (const auto& [user, movies] : userToMovies) {
            cout << "User " << user << ": ";
            for (const auto& [movie, rating] : movies) {
                cout << "(" << movie << ", " << rating << ") ";
            }
            cout << endl;
        }

        cout << "Movie -> Users:" << endl;
        for (const auto& [movie, users] : movieToUsers) {
            cout << "Movie " << movie << ": ";
            for (const auto& [user, rating] : users) {
                cout << "(" << user << ", " << rating << ") ";
            }
            cout << endl;
        }
    }
};
