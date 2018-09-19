/* Referenced:
 * - GeeksforGeeks
 * - http://www.geeksforgeeks.org/*/
 
 
 #include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :
		VectorSorter(name) {
}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {
}

void ShellSortOptimal::run_sort_algorithm() throw (string) {
	/***** Complete this member function. *****/
	int interval = 0;
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0) {
		for (int i = interval; i < size; i++) {
			Element temp = data[i];
			int j;
			for (j = i; j >= interval; j -= interval) {
				compare_count++;
				if (data[j - interval] > temp) {
					data[j] = data[j - interval];
					move_count++;
				} else
					break;
			}
			data[j] = temp;

		}

		interval = (interval - 1) / 3;
	}

}
