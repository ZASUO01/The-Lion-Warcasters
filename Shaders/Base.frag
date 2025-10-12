#version 330

// This corresponds to the output color to the color buffer
out vec4 outColor;
uniform vec3 uColor;

void main(){
	// Sample color from texture
    outColor = vec4(uColor, 1.0);
}