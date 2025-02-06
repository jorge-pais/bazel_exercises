# Bazel Exercises Repository

This repository contains a set of exercises designed to introduce developers to Bazel and demonstrate its capabilities. The exercises focus on building and extending a C++ CLI application using different Bazel rules.

## :school: Purpose of exercises

Bazel is a powerful build system that helps manage large-scale builds with efficiency and reliability. This repository aims to teach developers the fundamentals of Bazel, including:

- **How Bazel executes builds**: Understanding its execution model and caching mechanisms.
- **Basic concepts**:
  - **Labels**: Unique identifiers for build targets within the repository.
  - **Targets**: The elements Bazel builds, such as binaries, libraries, and tests.
  - **Rules**: The instructions that define how Bazel builds specific targets.
  - **BUILD** files: Configuration files where rules and targets are defined.
- **Using Bazel modules**: Managing external dependencies effectively.
- **Extending build functionality**: Writing custom code generators in Python and Java to integrate with Bazel.

The complete training is organized around one small C++ project which contains one base class and several derivative classes. Each exercise has dependency on previous exercises results, so for this reason, the results from all exercises have to be preserved. In case that solution has been lost from previous exercise, the branch named solution will kept all previous solutions.

> NOTE: This training is all about using Bazel, so the focus won't be on C++ application and it's features.

If you need an entry point for documentation, take a look at the following links:

- [Get started](https://bazel.build/concepts/build-ref) (If you are completely new to Bazel)
- [Bazel extended concepts](https://bazel.build/extending/concepts)
- [Bazel rules](https://bazel.build/rules/rules-tutorial)
- [YouTube Tutorial for Bazel beginners](https://www.youtube.com/watch?v=toPWLiUq5Ps)

## :computer: Getting Started

- **Fork the repository** using GitHub’s web interface.
- **Clone this repository**:
  ```bash
  git clone https://github.com/YOUR_USERNAME/bazel_exercises.git
  cd bazel_exercises
  ```
- **Follow the instructions** in each exercise to complete the tasks.

**Happy hacking!**

## :computer: Exercise 1: Setting Up the BUILD files for the C++ CLI Application

In this first exercise, we will focus on creating the necessary Bazel configuration to build the C++ application located in the `project/cli` folder. The goal is to set up a basic Bazel build system for a C++ application and verify that it works for the host platform.

### 🎯 Acceptance Criteria:

- The build system includes a MODULE.bazel file configured to pull rules_cc using bazel_dep.
- You can successfully build the C++ application for the host target.
- The application can be executed on the host after building.

### 🛠️ Steps to Complete:

1. **Add** MODULE.bazel:

   - Create a MODULE.bazel file in the root of the repository.
   - Use bazel_dep to pull the rules_cc dependency.

2. **Create** a BUILD Files:

   - Add a BUILD files in folders that contain .cpp code to define a Bazel target for each library and binary.
   - Ensure the target includes all source files.

3. **Build** and Run the Application:

   - Use Bazel to build the application for your host platform.
   - Run the resulting executable to verify everything is working.

### :briefcase: Key Takeaways

By completing this exercise, you will:

- ✅ Gain hands-on experience in setting up a Bazel build for a C++ application.
- ✅ Learn how to use MODULE.bazel and bazel_dep to manage external dependencies.
- ✅ Understand the basics of defining and building targets in Bazel.

Ready? Let’s get started! 🚀

## :computer: Exercise 2: Generating C++ Code Using a Python Code Generator in Bazel

In this exercise, we will extend our Bazel setup by integrating a Python-based code generator that produces C++ source files. The goal is to automate the code generation step within the Bazel build process, ensuring that the generated files are correctly included in the final application build.

### 🎯 Acceptance Criteria:

- Define a Bazel rule to run the existing Python script and generate .cpp and .h files.
- Ensure the generated files are used in the C++ build process.
- The final C++ application should compile and run, now including the generated code.

### 🛠️ Steps to Complete

1. **Create** a BUILD file inside the `project/python` directory:

   - Create a Bazel python rule to execute the existing Python script.

2. Define **custom Bazel rule** that will execute Python script over Python binary rule:

   - Ensure the rule implementation takes the necessary inputs and produces the expected .cpp and .h files.
   - Modify the C++ BUILD File (`project/cli/circle`)

3. Run the Bazel Build and Execute the Application:
   - Verify that the code generator runs automatically before compiling the C++ application.
   - Ensure that the generated files are included in the final binary.

### :briefcase: Key Takeaways

By completing this exercise, you will:

- ✅ Learn how to integrate Python-based code generation into a Bazel build.
- ✅ Understand how generated files can be seamlessly included in a multi-language project.
- ✅ Gain experience in defining Bazel rules for executing scripts and managing dependencies.

Ready to enhance the build process? 🚀

## :computer: Exercise 3 - Generating C++ Code Using a Java Code Generator in Bazel

In this exercise, we will further extend our Bazel setup by integrating a Java-based code generator that produces C++ source files. Similar to Exercise 2, the goal is to ensure that Bazel correctly runs the Java generator and incorporates the generated files into the final C++ application build.

### 🎯 Acceptance Criteria:

- Define a Bazel rule to execute the existing Java code generator, producing .cpp and .h files.
- Ensure the generated files are used in the C++ build process.
- The final C++ application should compile and run, including the newly generated code.

### 🛠️ Steps to Complete

1. **Create** a BUILD file inside the `project/java` directory:

   - Create a Bazel Java rule to execute the existing Java script.

2. Define **custom Bazel rule** that will execute Java script over Java binary rule:

   - Ensure the rule implementation takes the necessary inputs and produces the expected .cpp and .h files.
   - Modify the C++ BUILD File (`project/cli/rectangle`)

3. Run the Bazel Build and Execute the Application:
   - Verify that the Java code generator runs before compiling the C++ application.
   - Ensure that the generated files are included in the final binary.

### :briefcase: Key Takeaways

By completing this exercise, you will:

- ✅ Learn how to integrate Java-based code generation into a Bazel build.
- ✅ Understand how generated files from Java programs can be included in a multi-language project.
- ✅ Gain experience defining Bazel rules for executing Java applications and managing dependencies.

With this step complete, we fully automated Bazel build pipeline! 🚀

## ✨ Disclaimer

These exercises provide one possible solution for using Bazel to manage multi-language projects. It is intended as a learning resource and may not cover all possible use cases or best practices for every scenario.

## 📜 License

The entire training, including all code and exercises, is provided under the MIT License. You are free to use, modify, and distribute the material as permitted by the license.
