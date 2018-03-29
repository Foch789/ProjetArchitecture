//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

//Vertex Shader tres simple : translation (1, 1, 0)
uniform vec3 pos;

void main(void) {
//gl_FrontColor = gl_Color;
gl_TexCoord[0] = gl_MultiTexCoord0;
								vec4 point = vec4(gl_Vertex);

								point.x += pos.x;
								point.y += pos.y;
								point.z += pos.z;

								gl_Position = gl_ModelViewProjectionMatrix * point;
}
