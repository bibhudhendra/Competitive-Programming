package search.binary_search;

class BinarySeachPatterns {
    /*
     * Find the element index which is just greater than target
     */
    public static int findJustGreater(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    /*
     * Find element index greater than or equal to the target. In case of equality, return the index of the last occurrence of the same element.
     */
    public static int findGreaterOrEqualLast(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    /*
     * Find element index greater than or equal to the target. In case of equality, return the index of the first occurrence of the same element.
     */
    public static int findGreaterOrEqualFirst(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    /*
     * Find the element index which is just smaller than the target
     */
    public static int findJustSmaller(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    /*
     * Find the element index which is just smaller or equal to the target. In case of multiple occurrences, return the index of the first occurrence.
     */
    public static int findSmallerOrEqualFirst(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    /*
     * Find the element index which is just smaller or equal to the target. In case of multiple occurrences, return the index of the last occurrence.
     */
    public static int findSmallerOrEqualLast(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
}