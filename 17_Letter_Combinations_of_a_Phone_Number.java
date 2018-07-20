class Solution {

    private String[] letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public List<String> letterCombinations(String digits) {
        ArrayList<String> result = new ArrayList<>();

        /* Sanity check */
        if(digits.equals(""))
            return result;

        StringBuilder currentString = new StringBuilder();
        dfs(result, digits, currentString, 0);
        return result;
    }

    private void dfs(List<String> result, final String digits, StringBuilder currentString, int depth) {

        /* Reached end, append to result array */
        if(currentString.length() == digits.length()) {
            result.add(currentString.toString());
        }

        /* Otherwise, dfs next level */
        else {
            /* Get index into letters array */
            int index = Character.getNumericValue(digits.charAt(depth)) - 2;

            for(int i = 0; i < letters[index].length(); ++i) {
                currentString.append(letters[index].charAt(i));
                dfs(result, digits, currentString, depth + 1);
                currentString.deleteCharAt(currentString.length() - 1);
            }
        }
    }

}