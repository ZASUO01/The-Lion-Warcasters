#version 330

// Attribute 0 is position
layout (location = 0) in vec2 inPosition;

uniform mat4 uWorldTransform;
uniform mat4 uOrthoProj;
uniform vec3 uColor;

void main(){
	gl_Position = uOrthoProj * uWorldTransform * vec4(inPosition, 0.0, 1.0);
}