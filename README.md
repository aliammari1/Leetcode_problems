# Leetcode Problems

A comprehensive collection of LeetCode problem solutions organized by individual problem directories. This repository serves as a personal coding practice journal and tracks submission history across multiple attempts and languages.

## 🚀 Features

- **Organized Solutions**: Each problem in its own directory with submission history
- **Multiple Languages**: Solutions primarily in C++ and Java, with SQL for database problems
- **Submission Tracking**: Complete history of accepted, wrong answer, and runtime error submissions
- **Timestamped Solutions**: Each submission saved with exact timestamp
- **Problem Links**: Direct links to original LeetCode problems included in solution files

## 📊 Progress Statistics

| Language    | Files | Percentage |
|-------------|-------|------------|
| C++         | 496   | 72.7%      |
| Java        | 18    | 2.6%       |
| Oracle SQL  | 26    | 3.8%       |
| MySQL       | 2     | 0.3%       |
| **Total Problems** | **173** | **100%** |

*Last updated: 2025-06-26*

## 🛠️ Technologies Used

- **Primary Languages**: C++ (72.7%), Java (2.6%)
- **Database Languages**: Oracle SQL, MySQL
- **Tools**: VS Code, LeetCode Platform Integration
- **Platforms**: LeetCode

## 📁 Repository Structure

```
Leetcode_problems/
├── assets/
│   └── repo_image_Leetcode_problems.png
├── solutions/
│   ├── add-binary/
│   │   └── Accepted/
│   │       └── [timestamp]/
│   │           └── Solution.cpp
│   ├── add-two-integers/
│   │   └── Accepted/
│   │       └── [timestamp]/
│   │           └── Solution.java
│   ├── two-sum/
│   │   ├── Accepted/
│   │   │   └── [timestamp]/
│   │   │       └── Solution.cpp
│   │   ├── Runtime Error/
│   │   └── Wrong Answer/
│   ├── combine-two-tables/
│   │   └── Accepted/
│   │       └── [timestamp]/
│   │           └── Solution.oraclesql
│   └── [173 total problem directories]
├── LICENSE
└── README.md
```

### Directory Structure Explanation

Each problem follows this consistent structure:
- **Problem Directory**: Named using the LeetCode problem slug (e.g., `two-sum`)
- **Status Directories**: `Accepted/`, `Wrong Answer/`, `Runtime Error/`, `Time Limit Exceeded/`, `Compile Error/`
- **Timestamp Directories**: Each submission saved with exact timestamp
- **Solution Files**: Named by language (e.g., `Solution.cpp`, `Solution.java`, `Solution.oraclesql`)

## 🎯 Problem Categories

Based on the 173 solved problems, this repository covers a wide range of topics:

### Data Structures
- **Arrays**: Two Sum, Best Time to Buy and Sell Stock, Build Array from Permutation
- **Strings**: Valid Anagram, Longest Common Prefix, Reverse String
- **Linked Lists**: Reverse Linked List, Merge Two Sorted Lists, Middle of the Linked List
- **Trees**: Binary Tree Traversals, Maximum Depth of Binary Tree, Same Tree
- **Hash Tables**: Contains Duplicate, Single Number, Valid Anagram
- **Stacks**: Valid Parentheses, Min Stack, Baseball Game

### Algorithms
- **Math Problems**: Fibonacci Number, Power calculations, Palindrome Number
- **Binary Search**: Binary Search, First Bad Version, Search Insert Position
- **Two Pointers**: Two Sum II, Reverse String, Valid Palindrome
- **Simulation**: Fizz Buzz, Robot Return to Origin, Pascal's Triangle

### Database Problems (SQL)
- **Joins**: Combine Two Tables, Replace Employee ID
- **Aggregation**: Average Salary, Daily Leads and Partners
- **Filtering**: Big Countries, Not Boring Movies, Recyclable Products

## 🔍 Example Solutions

### C++ Solution Format
```cpp
// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int,int> m;
        for(int i = 0; i < size; i++) {
            if(m.find(target - nums[i]) != m.end())
                return {m.find(target-nums[i])->second, i};
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
```

### Java Solution Format
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        return new int[] {};
    }
}
```

### SQL Solution Format
```sql
-- https://leetcode.com/problems/combine-two-tables
SELECT firstName, lastName, city, state 
FROM person p 
LEFT JOIN address a ON p.personId = a.personId;
```

## 📝 Submission Status Categories

- **Accepted**: Successfully solved problems
- **Wrong Answer**: Incorrect logic or edge cases missed
- **Runtime Error**: Code compilation or execution issues
- **Time Limit Exceeded**: Algorithm optimization needed
- **Compile Error**: Syntax or compilation issues

## 🚀 Getting Started

### Prerequisites
- C++ compiler (for C++ solutions)
- Java 8+ (for Java solutions)
- MySQL/Oracle Database (for SQL solutions)
- Any code editor or IDE

### Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/aliammari1/Leetcode_problems.git
   cd Leetcode_problems
   ```

2. **Navigate to specific problem**
   ```bash
   cd solutions/two-sum/Accepted/[timestamp]/
   ```

3. **Run a C++ solution**
   ```bash
   g++ -o solution Solution.cpp
   ./solution
   ```

4. **Run a Java solution**
   ```bash
   javac Solution.java
   java Solution
   ```

5. **Execute SQL solution**
   ```sql
   -- Copy and paste SQL from Solution.oraclesql into your database client
   ```

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Add new solutions**: Follow the established directory structure
2. **Improve existing solutions**: Optimize algorithms or add alternative approaches
3. **Add documentation**: Provide clearer comments and explanations
4. **Fix issues**: Report and fix any problems in the solutions

### Contribution Guidelines

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-solution`)
3. Follow the established directory structure: `problem-name/status/timestamp/`
4. Include both solution file and info.txt metadata
5. Commit your changes (`git commit -m 'Add solution for Problem XYZ'`)
6. Push to the branch (`git push origin feature/new-solution`)
7. Open a Pull Request

## 📈 Study Plan

### Current Progress: 173 Problems Solved

#### Language Distribution
- **C++ Focus**: Master data structures and algorithms implementation
- **Java Practice**: Object-oriented problem solving approaches  
- **SQL Proficiency**: Database query optimization and joins

#### Problem-Solving Journey
- **Foundation Building**: Arrays, strings, and basic algorithms
- **Data Structure Mastery**: Linked lists, trees, and hash tables
- **Algorithm Implementation**: Search, traversal, and mathematical problems
- **Database Skills**: Complex queries and data manipulation

## 🏆 LeetCode Profile

Connect with me on LeetCode: [aliammari1](https://leetcode.com/aliammari1/)

## 🎯 Goals

- [x] Solve 100+ problems (173/100+ ✅)
- [x] Master C++ implementation
- [x] Learn Java fundamentals  
- [x] Practice SQL queries
- [ ] Reach 200 solved problems
- [ ] Add Python solutions
- [ ] Implement advanced algorithms
- [ ] Optimize existing solutions

## 📚 Resources

### Books
- "Cracking the Coding Interview" by Gayle McDowell
- "Elements of Programming Interviews" by Adnan Aziz
- "Algorithm Design Manual" by Steven Skiena
- "Introduction to Algorithms" by CLRS

### Online Resources
- [LeetCode](https://leetcode.com/) - Primary platform for problem solving
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Algorithm explanations
- [CP-Algorithms](https://cp-algorithms.com/) - Competitive programming algorithms
- [HackerRank](https://www.hackerrank.com/) - Additional practice

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