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
	m_O = A;
	m_d = B-A;
	//comprueba que no sean el mismo punto (distancia 0)
	if (m_d.length()>0.0) {
			//obtienes el vector normalizado
			m_d = m_d.normalize();
	}
	else {
		printf("Los puntos son iguales\n");
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
	float res = 0.0f; //u0
	/* =================== PUT YOUR CODE HERE ====================== */
	
	float denominador = m_d.dot(m_d);
	// COMPROBAR DENOMINADOR > 0.0
	if (denominador > 0.0) {
		res = (m_d.dot(P-m_O))/denominador;
	}
	else {
		printf("ERROR: denominador negativo\n");
	}
	
	/* =================== END YOUR CODE HERE ====================== */
	
	return res;
}

// @@ TODO: Calculate the minimum distance 'dist' from line to P
//
// dist = ||P - (m_o + u0*m_d)||
// Where u0 = paramDistance(P)

float Line::distance(const Vector3 & P) const {
	float res = 0.0f;
	
	/* =================== PUT YOUR CODE HERE ====================== */
	//calcular u0
	float u0 = paramDistance(P);
	
	//comprobar si u0 <0 (esta mal calculado en paramDistance)
	if (u0 > 0.0) {
		//calcular la distancia (res) en funcion de u0
		Vector3 v = P - (m_O + u0*m_d);
		//res = v.dot(v); //se puede hacer v.length()
		res = v.length();
	}
	else {
		printf("ERROR: u0 negativo");
	}
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
