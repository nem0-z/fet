#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>
#include <string>
#include <vector>

#include "environment.hpp"

// Interface type for a node
struct ExpressionNode {
  virtual ~ExpressionNode(){};
  virtual int evaluate(Environment& env) = 0;
};

struct NumberNode : public ExpressionNode {
  NumberNode(int v) : value{v} {}

  int evaluate(Environment& env) override { return value; }

  private:
  int value;
};

struct VariableNode : public ExpressionNode {
  VariableNode(const char* var) : id{var} {}

  int evaluate(Environment& env) override { return env.variables()[id]; }

  private:
  std::string id;
};

struct FunctionNode : public ExpressionNode {
  FunctionNode(std::vector<std::string> argument_names,
               std::vector<ExpressionNode*> body,
                ExpressionNode* retexpr)
      : argument_names{std::move(argument_names)}, body{body}, ret{retexpr} {}

  int evaluate(Environment& env) override {
    for (auto expr : body) {
      expr->evaluate(env);
    }

    env.variables()["return"] = ret->evaluate(env);
    return 0;
  }

  std::vector<std::string> argument_names;
  std::vector<ExpressionNode*> body;
  ExpressionNode* ret;
};

struct FunctionDefinitionNode : public ExpressionNode {
  FunctionDefinitionNode(std::string function_name,
                         std::vector<std::string> argument_names,
                         std::vector<ExpressionNode*> body,
                         ExpressionNode* retexpr)
      : function_name{std::move(function_name)},
        argument_names{std::move(argument_names)},
        body{body},
        ret{retexpr} {}

  int evaluate(Environment& env) override {
    env.functions()[function_name] = new FunctionNode(std::move(argument_names), std::move(body), ret);
    return 0;
  }

  std::vector<std::string> argument_names;
  std::string function_name;
  std::vector<ExpressionNode*> body;
  ExpressionNode* ret;
};

struct FunctionCallNode : public ExpressionNode {
  FunctionCallNode(std::string function_name,
                   std::vector<ExpressionNode*> argument_values)
      : function_name{std::move(function_name)},
        argument_values{std::move(argument_values)} {}
  int evaluate(Environment& env) override {
    if (env.functions().find(function_name) == env.functions().end())
        return -1;

    auto fun = env.functions()[function_name];
    if (argument_values.size() != fun->argument_names.size())
        return -1;

    for (int i = 0; i < fun->argument_names.size(); ++i) {
        env.variables()[fun->argument_names[i]] = argument_values[i]->evaluate(env);
    }

    fun->evaluate(env);

    return env.variables()["return"];
  }
//
  std::string function_name;
  std::vector<ExpressionNode*> argument_values;
};

struct PlusNode : public ExpressionNode {
  PlusNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) + right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct MinusNode : public ExpressionNode {
  MinusNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) - right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct AssignmentNode : public ExpressionNode {
  AssignmentNode(const char* id, ExpressionNode* rhs) : id{id}, right{rhs} {}

  int evaluate(Environment& env) override {
    auto val = right->evaluate(env);
    env.variables()[id] = val;
    return val;
  }

  std::string id;
  ExpressionNode* right = nullptr;
};

struct IfNode : public ExpressionNode {
  IfNode(ExpressionNode* cond, ExpressionNode* body)
      : condition{cond}, body{body} {}
  int evaluate(Environment& env) override {
    if (condition->evaluate(env)) return body->evaluate(env);
    return 0;
  }

  private:
  ExpressionNode* condition = nullptr;
  ExpressionNode* body = nullptr;
};

struct PrintNode : public ExpressionNode {
  PrintNode(ExpressionNode* value) : value{value} {}

  int evaluate(Environment& env) override {
    printf("> %d\n", value->evaluate(env));
    return 0;
  }

  ExpressionNode* value = nullptr;
};

struct WhileNode : public ExpressionNode {
  WhileNode(ExpressionNode* cond, std::vector<ExpressionNode*> body)
      : condition{cond}, body{body} {}
  int evaluate(Environment& env) override {
      while (condition->evaluate(env)) {
          for (const auto &expr: body) {
            expr->evaluate(env);
          }
      }

      return 0;
  }

  private:
  ExpressionNode* condition = nullptr;
  std::vector<ExpressionNode*> body;
};

struct MultiplyNode : public ExpressionNode {
  MultiplyNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) * right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct DivideNode : public ExpressionNode {
  DivideNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) / right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct EqualityNode : public ExpressionNode {
  EqualityNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) == right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct InEqualityNode : public ExpressionNode {
  InEqualityNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) != right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct LessThanNode : public ExpressionNode {
  LessThanNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) < right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct GreaterThanNode : public ExpressionNode {
  GreaterThanNode(ExpressionNode* lhs, ExpressionNode* rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment& env) override {
    return left->evaluate(env) > right->evaluate(env);
  }

  private:
  ExpressionNode* left = nullptr;
  ExpressionNode* right = nullptr;
};

struct IfElseNode : public ExpressionNode {
  IfElseNode(ExpressionNode* cond, ExpressionNode* first, ExpressionNode* second)
      : condition{cond}, iftrue{first}, iffalse{second} {}
  int evaluate(Environment& env) override {
    if (condition->evaluate(env)) return iftrue->evaluate(env);
    return iffalse->evaluate(env);
  }

  private:
  ExpressionNode* condition = nullptr;
  ExpressionNode* iftrue = nullptr;
  ExpressionNode* iffalse = nullptr;
};

#endif  // EXPRESSION_TREE_H
