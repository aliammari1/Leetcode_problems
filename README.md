# Leetcode Problems

A comprehensive collection of LeetCode problem solutions organized by topic and difficulty level. This repository serves as a personal coding practice journal and reference for algorithmic problem-solving patterns.

## 🚀 Features

- **Organized Solutions**: Problems categorized by data structures and algorithms
- **Multiple Languages**: Solutions implemented in various programming languages
- **Difficulty Levels**: Easy, Medium, and Hard problems clearly marked
- **Detailed Explanations**: Comments and explanations for complex solutions
- **Time/Space Complexity**: Big O analysis for each solution
- **Problem Links**: Direct links to original LeetCode problems
- **Progress Tracking**: Visual representation of solved problems
- **Pattern Recognition**: Solutions grouped by common algorithmic patterns

## 📊 Progress Statistics

| Difficulty | Solved | Total | Percentage |
|------------|--------|-------|------------|
| Easy       | 0      | 700+  | 0%         |
| Medium     | 0      | 1500+ | 0%         |
| Hard       | 0      | 600+  | 0%         |
| **Total**  | **0**  | **2800+** | **0%** |

*Last updated: 2025-06-25*

## 🛠️ Technologies Used

- **Primary Languages**: Python, Java, JavaScript, C++
- **Supporting Languages**: TypeScript, Go, Rust
- **Tools**: VS Code, IntelliJ IDEA, Git
- **Platforms**: LeetCode, GitHub

## 📁 Repository Structure

```
Leetcode_problems/
├── assets/
│   └── repo_image_Leetcode_problems.png
├── Array/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
├── String/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
├── LinkedList/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
├── Tree/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
├── Dynamic_Programming/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
├── Graph/
│   ├── Medium/
│   └── Hard/
├── Backtracking/
│   ├── Medium/
│   └── Hard/
├── Math/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
├── patterns/
│   ├── sliding_window.md
│   ├── two_pointers.md
│   ├── fast_slow_pointers.md
│   ├── merge_intervals.md
│   └── topological_sort.md
├── templates/
│   ├── binary_search.py
│   ├── dfs_template.py
│   ├── bfs_template.py
│   └── dp_template.py
├── LICENSE
└── README.md
```

## 🎯 Problem Categories

### Data Structures
- **Arrays & Hashing**: Two Sum, Best Time to Buy and Sell Stock
- **Strings**: Valid Anagram, Longest Substring Without Repeating Characters
- **Linked Lists**: Reverse Linked List, Merge Two Sorted Lists
- **Trees**: Binary Tree Inorder Traversal, Maximum Depth of Binary Tree
- **Graphs**: Number of Islands, Course Schedule
- **Heaps**: Kth Largest Element, Top K Frequent Elements
- **Tries**: Implement Trie, Word Search II

### Algorithms
- **Sorting & Searching**: Binary Search, Merge Sort
- **Dynamic Programming**: Climbing Stairs, Coin Change
- **Greedy**: Jump Game, Gas Station
- **Backtracking**: Permutations, N-Queens
- **Divide & Conquer**: Merge Sort, Quick Sort
- **Bit Manipulation**: Single Number, Counting Bits

## 🔍 Common Patterns

### 1. Two Pointers
```python
def two_pointers_template(arr):
    left, right = 0, len(arr) - 1
    while left < right:
        # Process current pair
        # Move pointers based on condition
        pass
```

### 2. Sliding Window
```python
def sliding_window_template(arr, k):
    window_start = 0
    for window_end in range(len(arr)):
        # Expand window
        # Shrink window if needed
        pass
```

### 3. Binary Search
```python
def binary_search_template(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```

## 📝 Solution Format

Each solution follows a consistent format:

```python
"""
Problem: [Problem Number] - [Problem Title]
Link: https://leetcode.com/problems/problem-title/
Difficulty: Easy/Medium/Hard
Topics: Array, Hash Table, etc.

Description:
[Brief problem description]

Approach:
[Explanation of the solution approach]

Time Complexity: O(?)
Space Complexity: O(?)
"""

class Solution:
    def solutionMethod(self, params):
        # Implementation
        pass

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # Test cases here
```

## 🚀 Getting Started

### Prerequisites
- Python 3.8+ (primary language)
- Java 11+ (optional)
- Node.js 14+ (for JavaScript solutions)
- Any code editor or IDE

### Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/aliammari1/Leetcode_problems.git
   cd Leetcode_problems
   ```

2. **Navigate to specific problem**
   ```bash
   cd Array/Easy/
   ```

3. **Run a solution**
   ```bash
   python3 two_sum.py
   ```

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Add new solutions**: Follow the established format and structure
2. **Improve existing solutions**: Optimize time/space complexity
3. **Add explanations**: Provide clearer comments and documentation
4. **Fix bugs**: Report and fix any issues in the solutions

### Contribution Guidelines

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-solution`)
3. Follow the solution format template
4. Include test cases
5. Commit your changes (`git commit -m 'Add solution for Problem XYZ'`)
6. Push to the branch (`git push origin feature/new-solution`)
7. Open a Pull Request

## 📈 Study Plan

### Beginner (0-50 problems)
- Focus on easy problems
- Master basic data structures (arrays, strings, linked lists)
- Learn fundamental algorithms (sorting, searching)

### Intermediate (50-200 problems)
- Tackle medium difficulty problems
- Study dynamic programming and greedy algorithms
- Practice tree and graph problems

### Advanced (200+ problems)
- Solve hard problems
- Master advanced algorithms
- Focus on optimization and edge cases

## 🏆 LeetCode Profile

Connect with me on LeetCode: [aliammari1](https://leetcode.com/aliammari1/)

## 🎯 Goals

- [ ] Solve 100 Easy problems
- [ ] Solve 100 Medium problems
- [ ] Solve 50 Hard problems
- [ ] Master all common patterns
- [ ] Achieve 1000+ rating
- [ ] Complete all explore cards

## 📚 Resources

### Books
- "Cracking the Coding Interview" by Gayle McDowell
- "Elements of Programming Interviews" by Adnan Aziz
- "Algorithm Design Manual" by Steven Skiena

### Online Resources
- [LeetCode](https://leetcode.com/)
- [NeetCode](https://neetcode.io/)
- [AlgoMonster](https://algo.monster/)
- [Blind 75](https://leetcode.com/discuss/general-discussion/460599/blind-75-leetcode-questions)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **LeetCode** for providing an excellent platform for algorithmic practice
- **Programming community** for sharing knowledge and solutions
- **Open source contributors** for inspiration and learning resources

## 📧 Contact

**Ali Ammari** - [GitHub Profile](https://github.com/aliammari1)

Project Link: [https://github.com/aliammari1/Leetcode_problems](https://github.com/aliammari1/Leetcode_problems)

---

*Happy Coding! 🚀*

## Repository Visualization
![Repository Visualization](https://raw.githubusercontent.com/aliammari1/Leetcode_problems/main/assets/repo_image_Leetcode_problems.png)