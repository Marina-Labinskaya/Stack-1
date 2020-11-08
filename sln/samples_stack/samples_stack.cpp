// samples_stack.cpp: определяет точку входа для консольного приложения.
//

#include "stack.h"
#include <string>
bool is_open_bracket(char c)
{
	return ((c=='{')||(c=='[')||(c=='('));
}
bool is_closing_bracket(char c)
{
	return ((c=='}')||(c==']')||(c==')'));
}
char get_open_bracket_pair(char bracket)
{
	switch (bracket)
	{
	case '}': return '{';
		      break;
	case ']': return '[';
		      break;
	case ')': return '(';
		      break;
	default : return 0;
		      break;
	}
}
bool are_brackets_good(const std::string &str)
{
	bool flag=true;
	Stack<char> s;
	for (size_t i=0; i<str.size(); ++i)
	{
		if (is_open_bracket(str[i]))
			s.push(str[i]);
		else
			if (is_closing_bracket(str[i]))
			{
				char open_bracket=get_open_bracket_pair(str[i]);
				if ((s.empty()!=true)&&(s.top()==open_bracket))
					s.pop();
				else { flag=false; break; }
			}
	}
	return ((flag)&&(s.empty()));
}

int main(int argc, char** argv)
{
	std::cout<<are_brackets_good(argv[1])<<std::endl;
	return 0;
}

