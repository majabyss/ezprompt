#include <iostream>
#include <print>
#include <string>
#include <ostream>
#include <fstream>

struct sections {
    std::string role;
    std::string obj;
    std::string context;
    std::string task;
    std::string constraints;
    std::string out_fmt;
    std::string examples;
    std::string reasoning;
};

int main() {
    sections s;
    std::string ans;
    std::println("Is your agent made by Anthropic? (e.g. Claude) y/n");
    std::getline(std::cin, ans);
    if (ans != "y" && ans != "n") {std::cerr << "Error: Unexpected response, please respond with y or n" << std::endl; return 1;}

    std::println("What is this agent's role? (e.g. An experienced software engineer)");
    std::getline(std::cin, s.role);
    std::println("What is this agent's objective? (e.g. Build an app that tracks my daily routine) <- Keep this to one sentence.");
    std::getline(std::cin, s.obj);
    std::println("What context should the agent know? (e.g. I am a very busy person and can't keep track of my day to day life)");
    std::getline(std::cin, s.context);
    std::println("What is the task for this agent? (e.g. Step 1... Step 2... etc.) <- This is for more detailed instructions than the end objective.");
    std::getline(std::cin, s.task);
    std::println("What constraints should this agent follow? (e.g. Never use old C++ versions)");
    std::getline(std::cin, s.constraints);
    std::println("What should the output format be? (e.g. A file, some text, etc.)");
    std::getline(std::cin, s.out_fmt);
    std::println("(Optional) Are there any specific examples the agent should know? (e.g. X fails to load on Y system)");
    std::getline(std::cin, s.examples);
    std::println("(Optional) How should the agent think/reason? (e.g. Think step by step)");
    std::getline(std::cin, s.reasoning);

    if (ans == "y") {
        std::ofstream out("prompt.md");
        std::println(out, "<role>\n{}.\n</role>\n<objective>\n{}\n</objective>\n<context>\n{}\n</context>\n<task>\n{}\n</task>\n<constraints>\n{}\n</constraints>\n<output_format>\n{}\n</output_format>\n<examples>\n{}\n</examples>\n<reasoning>\n{}\n</reasoning>", s.role, s.obj, s.context, s.task, s.constraints, s.out_fmt, s.examples, s.reasoning);    
    } else if (ans == "n") {
        std::ofstream out("prompt.md");
        std::println(out, "## ROLE\n{}\n\n## OBJECTIVE\n{}\n\n## CONTEXT\n{}\n\n## TASK\n{}\n\n## CONSTRAINTS\n{}\n\n## OUTPUT FORMAT\n{}\n\n## EXAMPLES\n{}\n\n## REASONING\n{}", s.role, s.obj, s.context, s.task, s.constraints, s.out_fmt, s.examples, s.reasoning);
    }
    return 0;
}
