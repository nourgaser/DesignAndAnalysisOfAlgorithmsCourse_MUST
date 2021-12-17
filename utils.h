#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <chrono>
#include <sys/time.h>
#include <ctime>

using std::cout, std::endl, std::cin, std::vector;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

using std::vector, std::cout, std::swap;

vector<int> exhaustiveSearch(const vector<vector<int>> &m);
// vector<int> hungarianMethod(const vector<vector<int>> &m);

void printMatrix(const vector<vector<int>> &m);
void printMatrix(const vector<vector<int>> &m, const vector<int> &highlightedIndices);

void printVector(const vector<int> &v);

void allPermutations(vector<int> v, int start, int end, vector<vector<int>> &res);
