/* Expression types */
enum EXP_TYPE {INT, LET, MULT, ADD};

/* Parsed form of expression */
class Expression {
    friend class Solution;
    EXP_TYPE type;
    vector<string> variable;
    vector<string> value;
    string expression1;
    string expression2;
};

class Solution {

private:
    /* Parse given string into Expression class */ 
    Expression parse(const string & expression) {
        Expression result;
        if(expression[0] != '(' ) {
            /* Immediate number or variable */
            result.type = INT;
            result.expression1 = expression;
        }
        else {
            vector<string> exp_splitted = split(expression);
            /* Parse expression type */
            if(exp_splitted[0] == "let") {
                result.type = LET;
            } else if(exp_splitted[0] == "add") {
                result.type = ADD;
            } else if(exp_splitted[0] == "mult") {
                result.type = MULT;
            } else {
                assert(false);
            }
            /* Parse expression value */
            if(result.type == LET) {
                for(int i = 1; i < exp_splitted.size() - 1; i += 2) {
                    result.variable.push_back(exp_splitted[i]);
                    result.value.push_back(exp_splitted[i + 1]);
                }
                result.expression1 = exp_splitted.back();
            } else {
                result.expression1 = exp_splitted[1];
                result.expression2 = exp_splitted[2];
            }
        }
        return result;
    }

    /* Split into sub-expressions separated by parenthesis */
    vector<string> split(const string & expression) {
        /* Strip outer parenthesis */
        int cursor = 1, substr_len = 0, p_cnt = 0;
        vector<string> result;
        while(cursor < expression.length() - 1) {
            if(expression[cursor] == '(') {
                p_cnt += 1;
                substr_len += 1;
            } else if(expression[cursor] == ')') {
                p_cnt -= 1;
                substr_len += 1;
            } else if(expression[cursor] == ' ' && p_cnt == 0) {
                result.push_back(expression.substr(cursor - substr_len, substr_len));
                substr_len = 0;
            } else {
                substr_len += 1;
            }
            cursor += 1;
        }
        result.push_back(expression.substr(cursor - substr_len, substr_len));
        return result;
    }

    /* Recursive evaluation */
    int env_helper(const string & expression, unordered_map<string, int> env) {
        Expression exp_parsed = parse(expression);
        if(exp_parsed.type == INT) {
            /* Immediate number or variable in scope */
            if((exp_parsed.expression1[0] >= '0' && exp_parsed.expression1[0] <= '9') || 
                exp_parsed.expression1[0] == '-') {
                return stoi(exp_parsed.expression1);
            } else {
                return env[exp_parsed.expression1];
            }
        } else if(exp_parsed.type == LET) {
            /* Eval and update var bindings in let scope, then eval expression */
            for(int i = 0; i < exp_parsed.variable.size(); ++i) {
                env[exp_parsed.variable[i]] = env_helper(exp_parsed.value[i], env);
            }
            return env_helper(exp_parsed.expression1, env);
        } else if(exp_parsed.type == MULT) {
            /* Evaluate mult recursively */
            return env_helper(exp_parsed.expression1, env) * 
                    env_helper(exp_parsed.expression2, env);
        } else if(exp_parsed.type == ADD) {
            /* Evaluate add recursively */
            return env_helper(exp_parsed.expression1, env) + 
                    env_helper(exp_parsed.expression2, env);
        } else {
            assert(false);
        }
    }

public:
    int evaluate(string expression) {
        /* Initialize with empty closure */
        return env_helper(expression, unordered_map<string, int>());
    }
};