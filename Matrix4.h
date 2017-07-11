#pragma once

class Matrix4 {
public:
	double values[4][4];

	Matrix4();
	Matrix4(const Matrix4 &matrix);
	
	// multiplication
	Matrix4 operator*(const Matrix4 &matrix) {
		Matrix4 result;

		for (int i = 0; i < 4; i++) {
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				values[k][i] =
					values[i][0] * matrix.values[0][k] +
					values[i][1] * matrix.values[1][k] +
					values[i][2] * matrix.values[2][k] +
					values[i][3] * matrix.values[3][k];
			}
		}

		return result;
	}
};
