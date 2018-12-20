cmake_minimum_required(VERSION 3.12)
project(FirstStone)

set(CMAKE_CXX_STANDARD 14)

add_executable(FirstStone main.cpp Expression.h Number.cpp Number.h BinaryExpression.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h CommandExpression.cpp CommandExpression.h Command.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h Lexer.cpp Lexer.h Parser.cpp Parser.h Shunting.cpp Shunting.h EqualCommand.cpp EqualCommand.h SleepCommand.cpp SleepCommand.h)