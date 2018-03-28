//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

//Vertex Shader tres simple : translation (1, 1, 0)
uniform float cputime;
//uniform /*type*/ alea

void main(void) {
								vec4 point = vec4(gl_Vertex);

								//point.z = ;

								//gl_FrontColor = gl_Color;

								gl_Position = gl_ModelViewProjectionMatrix * point;
}
