#include <iostream>
#include <sstream>
#include <memory>

// Forward declarations
class Number;
class Add;
class Multiply;

// Visitor interface
class ExprVisitor
{
public:
    virtual void visit(Number *n) = 0;
    virtual void visit(Add *a) = 0;
    virtual void visit(Multiply *m) = 0;
    virtual ~ExprVisitor() = default;
};

// Expression base class
class Expr
{
public:
    virtual void accept(ExprVisitor &v) = 0;
    virtual ~Expr() = default;
};

// Number node
class Number : public Expr
{
public:
    int value;
    Number(int v) : value(v) {}
    void accept(ExprVisitor &v) override
    {
        v.visit(this);
    }
};

// Add node
class Add : public Expr
{
public:
    std::unique_ptr<Expr> left, right;
    Add(Expr *l, Expr *r) : left(l), right(r) {}
    void accept(ExprVisitor &v) override
    {
        v.visit(this);
    }
};

// Multiply node
class Multiply : public Expr
{
public:
    std::unique_ptr<Expr> left, right;
    Multiply(Expr *l, Expr *r) : left(l), right(r) {}
    void accept(ExprVisitor &v) override
    {
        v.visit(this);
    }
};

// Visitor for evaluation
class EvalVisitor : public ExprVisitor
{
public:
    int result = 0;

    void visit(Number *n) override
    {
        result = n->value;
    }

    void visit(Add *a) override
    {
        a->left->accept(*this);
        int leftVal = result;
        a->right->accept(*this);
        int rightVal = result;
        result = leftVal + rightVal;
    }

    void visit(Multiply *m) override
    {
        m->left->accept(*this);
        int leftVal = result;
        m->right->accept(*this);
        int rightVal = result;
        result = leftVal * rightVal;
    }
};

// Visitor for printing
class PrintVisitor : public ExprVisitor
{
public:
    std::ostringstream out;

    void visit(Number *n) override
    {
        out << n->value;
    }

    void visit(Add *a) override
    {
        out << "(";
        a->left->accept(*this);
        out << " + ";
        a->right->accept(*this);
        out << ")";
    }

    void visit(Multiply *m) override
    {
        out << "(";
        m->left->accept(*this);
        out << " * ";
        m->right->accept(*this);
        out << ")";
    }

    std::string getResult()
    {
        return out.str();
    }
};

int main()
{
    unique_ptr<Expr> expr = make_unique<Multiply>(
        new Add(new Number(3), new Number(4)), new Number(5))
        EvalVisitor eval;
    expr->accept(eval);
}