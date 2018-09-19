/* Referenced:
 * - GeeksforGeeks
 * - http://www.geeksforgeeks.org/*/
 
 #include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) :
		VectorSorter(name) {
}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {
}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string) {

	for (int gap = size / 2; gap > 0; gap /= 2) {
		
		for (int i = gap; i < size; i += 1) {
		
			Element temp = data[i];
			int j;
			for (j = i; j >= gap; j -= gap) {
				compare_count++;
				if (data[j - gap] > temp) {
					data[j] = data[j - gap];
					move_count++;
				} else
					break;
			}

			data[j] = temp;

		}
	}

}
