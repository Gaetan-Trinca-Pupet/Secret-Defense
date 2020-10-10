#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 255)out;

uniform int radius;
uniform int nbangles;
uniform int width;
uniform int height;
uniform float deg;

const float PI = 3.1415926535;

void main(){
	float angle = -PI/2;
	int i = 0;
	while(angle > -deg - PI/2){
		vec4 offset = vec4(cos(angle) * radius/width, -sin(angle) * radius/height, 0.0, 0.0);
		gl_Position = gl_in[0].gl_Position + offset;
		EmitVertex();
		++i;
		
		gl_Position = gl_in[0].gl_Position;
		EmitVertex();
		angle = angle - 2*PI/nbangles;
		++i;
	}
	vec4 offsetlastvertex = vec4(cos(deg) * radius/width, -sin(deg) * radius/height, 0.0, 1.0);
	EmitVertex();
	EndPrimitive();
}