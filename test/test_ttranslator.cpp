#include "expression.h"

#include <gtest.h>

TEST(TExpression, can_create_expression)
{
	ASSERT_NO_THROW(Expression expr("3*2-4"));
}

TEST(TExpression, impossible_division_by_zero)
{
	Expression expr("34.4/0");
	ASSERT_ANY_THROW(expr.solve());
}

TEST(TExpression, can_add)
{
	Expression expr1("3++4.2");
	Expression expr2("2+3.8");
	double d = 2 + 3.8;
	ASSERT_ANY_THROW(expr1.solve());
	EXPECT_EQ(5.8, expr2.solve());
}
TEST(TExpression, can_subtract)
{
	Expression expr1("3-4.2-");
	Expression expr2("2-3.8");
	double d = 2 - 3.8;

	ASSERT_ANY_THROW(expr1.solve());
	EXPECT_EQ(d, expr2.solve());
}
TEST(TExpression, can_multiply)
{
	Expression expr1("3*4.2**");
	Expression expr2("2*3.8");
	double d = 2 * 3.8;

	ASSERT_ANY_THROW(expr1.solve());
	EXPECT_EQ(d, expr2.solve());
}
TEST(TExpression, can_divide)
{
	Expression expr1("34/2/3");
	Expression expr2("3.8/2");
	double d = 3.8 / 2;

	ASSERT_NO_THROW(expr1.solve());
	EXPECT_EQ(d, expr2.solve());
}
TEST(TExpression, invalid_brackets) {
	Expression expr1("((3.8/2)");
	Expression expr2("((3.8/2)+1))");
	Expression expr3("(3.8/2+1)(2+2))");

	ASSERT_ANY_THROW(expr1.solve());
	ASSERT_ANY_THROW(expr2.solve());
	ASSERT_ANY_THROW(expr3.solve());
}
TEST(TExpression, combination_of_operations_without_errors) {
	Expression expr("(3.45+4)*((45/5-2)+5)");
	ASSERT_NO_THROW(expr.solve());
}
TEST(TExpression, combination_of_operations_and_priority_with_correct_answer) {
	Expression expr("(3.45+4)*((45/5.0-2)+5.0)");
	double d = (3.45 + 4) * ((45 / 5.0 - 2) + 5.0);
	EXPECT_EQ(d, expr.solve());
}

