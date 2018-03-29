//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

//Vertex Shader tres simple : translation (1, 1, 0)

uniform vec3 centre_deformation;
uniform vec3 vecteur_deformation;
uniform float rayon_deformation;

varying float VFactif;

void main(void) {
								vec4 point = vec4(gl_Vertex);
/*
								float d = distance(vec4(centre_deformation, 1.0), point);

								//gl_FrontColor = gl_Color;
gl_TexCoord[0] = gl_MultiTexCoord0;
point.xyz = point.xyz + 40;
								VFactif = 0.0;
								if (d < rayon_deformation) {
																point.xyz = point.xyz + 40;//(1.0 - (d / rayon_deformation)) * vecteur_deformation.xyz;
																VFactif = 1.0;
								}
*/
point.x = point.x + 40;
								gl_Position = gl_ModelViewProjectionMatrix * point;
}
