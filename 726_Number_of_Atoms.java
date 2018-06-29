import java.util.*;

class Solution {
    
    /* Tokenize the string */
    private static ArrayList<String> tokenize(String formula) {
        ArrayList<String> result = new ArrayList<>();
        int start = 0, end = 0;
        while(true) {
            /* Move start and end together */
            if(start == formula.length()) {
                return result;
            }
            while(formula.charAt(start) == ')' || formula.charAt(start) == '(') {
                start += 1; end += 1;
                if(start == formula.length()) {
                    return result;
                }
                if(formula.charAt(start) == '(') {
                    result.add("(");
                }
            }
            /* Start matching text */
            end += 1;
            boolean left_parenthesis = false;
            while(true) {
                if(end == formula.length() || Character.isUpperCase(formula.charAt(end)) || 
                    formula.charAt(end) == '(' || formula.charAt(end) == ')') {
                    if(end < formula.length() && formula.charAt(end) == '(') {
                        left_parenthesis = true;
                    }
                    break;
                }
                end += 1;
            }
            result.add(formula.substring(start, end));
            if(left_parenthesis) {
                result.add("(");
            }
            start = end;
        }
    }
    
    public String countOfAtoms(String formula) {
        ArrayList<String> tokens = tokenize(formula);
        System.out.println(tokens);
        TreeMap<String, Integer> c = new TreeMap<>();
        Stack<Integer> weights = new Stack<>();
        Stack<String> order = new Stack<>();
        int weight_total = 1;
        for(int i = tokens.size() - 1; i >= 0; --i) {
            String cur = tokens.get(i);
            if(Character.isAlphabetic(cur.charAt(cur.length() - 1))) {
                /* A new element */ 
                if(c.containsKey(cur)) {
                    c.put(cur, c.get(cur) + weight_total);
                } else {
                    c.put(cur, weight_total);
                }
                order.push(cur);
            } else if(Character.isAlphabetic(cur.charAt(0))) {
                /* New elements of same kind */
                int count = 0, cursor = cur.length() - 1, base = 1;
                while(Character.isDigit(cur.charAt(cursor))) {
                    count += base * Character.getNumericValue(cur.charAt(cursor));
                    cursor -= 1;
                    base *= 10;
                }
                String element = cur.substring(0, cursor + 1);
                if(c.containsKey(element)) {
                    c.put(element, c.get(element) + count * weight_total);
                } else {
                    c.put(element, count * weight_total);
                }
                order.push(element);
            } else if(cur.length() == 1 && cur.charAt(0) == '(') {
                /* Hit l-parenthesis, refactor weight */
                weight_total /= weights.pop();
            } else {
                /* Hit number, factor weights */
                weights.push(Integer.parseInt(cur));
                weight_total *= weights.peek(); 
            }
        }
        StringBuilder builder = new StringBuilder();
        for(Map.Entry<String, Integer> entry : c.entrySet()) {
            builder.append(entry.getKey());
            if(entry.getValue() > 1) {
                builder.append(entry.getValue());
            }
        }
        return builder.toString();
    }

}

