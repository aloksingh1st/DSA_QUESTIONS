class Solution {

    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    function combinationSum2($candidates, $target) {
        $result = [];
        sort($candidates); // Sort to handle duplicates more effectively
        $this->backtrack($candidates, $target, [], 0, $result);
        return $result;
    }

    function backtrack($candidates, $target, $current, $start, &$result) {
        if ($target == 0) {
            $result[] = $current; // Valid combination
            return;
        }

        for ($i = $start; $i < count($candidates); $i++) {
            // Skip duplicate numbers at the same level
            if ($i > $start && $candidates[$i] == $candidates[$i - 1]) {
                continue;
            }

            // Stop if the current number exceeds the remaining target
            if ($candidates[$i] > $target) {
                break;
            }

            // Include the current number and move to the next level
            $current[] = $candidates[$i];
            $this->backtrack($candidates, $target - $candidates[$i], $current, $i + 1, $result);
            array_pop($current); // Backtrack
        }
    }
}