#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "line.h"
#include "constants.h"
#include "tools.h"

Line::Line() : m_O(Vector3::ZERO), m_d(Vector3::UNIT_Y) {}
Line::Line(const Vector3 & o, const Vector3 & d) : m_O(o), m_d(d) {}
Line::Line(const Line & line) : m_O(line.m_O), m_d(line.m_d) {}

Line & Line::operator=(const Line & line) {
	if (&line != this) {
		m_O = line.m_O;
		m_d = line.m_d;
	}
	return *this;
}

// @@ TODO: Set line to pass through two points A and B
//
// Note: Check than A and B are not too close!

void Line::setFromAtoB(const Vector3 & A, const Vector3 & B) {
	/* =================== PUT YOUR CODE HERE ====================== */
	//obtienes la distancia
	Vector3 v_aux = B-A;
	//comprueba que no sean el mismo punto (distancia 0)
	if (v_aux.isZero()) {
		//comprueba que la distancia sea positiva
		if (v_aux.length > 0.0) {
			//obtienes el vector normalizado
			m_d = v_aux.normalize();
		}	
	}
	
	
	/* =================== END YOUR CODE HERE ====================== */
}

// @@ TODO: Give the point corresponding to parameter u

Vector3 Line::at(float u) const {
	Vector3 res;
	/* =================== PUT YOUR CODE HERE ====================== */

	res = m_O + u * m_d;

	/* =================== END YOUR CODE HERE ====================== */
	return res;
}

// @@ TODO: Calculate the parameter 'u0' of the line point nearest to P
//
// u0 = m_d*(P-m_o) / m_d*m_d , where * == dot product

float Line::paramDistance(const Vector3 & P) const {
	float res = 0.0f;

    //// COMPROBAR DENOMINADOR > 0.0
	float denominador = m_d.dot(m_d);

	/* =================== PUT YOUR CODE HERE ====================== */
	//res = m_d DOT (P-m_O)/ (m_d*m_d);
	/* =================== END YOUR CODE HERE ====================== */
	return res;
}

// @@ TODO: Calculate the minimum distance 'dist' from line to P
//
// dist = ||P - (m_o + u0*m_d)||
// Where u0 = paramDistance(P)

float Line::distance(const Vector3 & P) const {
	float res = 0.0f;
	float u0 = 0.0f;
	/* =================== PUT YOUR CODE HERE ====================== */
	//calcular u0
	u0 = this.paramDistance(P);
	//comprobar si u0 <0 (esta mal calculado en paramdistance)
	
	//calcular la distancia (res) en funcion de u0

	/* =================== END YOUR CODE HERE ====================== */
	return res;
}

void Line::print() const {
	printf("O:");
	m_O.print();
	printf(" d:");
	m_d.print();
	printf("\n");
}
