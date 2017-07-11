#include "Matrix4.h"

Matrix4::Matrix4() {
	// identity matrix
	values[0][0] = 1;
	values[1][1] = 1;
	values[2][2] = 1;
	values[3][3] = 1;
}

Matrix4::Matrix4(const Matrix4 &matrix) {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			values[i][k] = matrix.values[i][k];
		}
	}
}
