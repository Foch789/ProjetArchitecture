//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

//Vertex Shader tres simple : translation (1, 1, 0)
uniform vec3 pos;

uniform vec3 tabcentre[100];
uniform vec3 tabdef[100];
uniform float tabrayon[100];

uniform float time;

varying float VFactif;

void main(void) {

								gl_TexCoord[0] = gl_MultiTexCoord0;
								vec4 point = vec4(gl_Vertex);

								point.x += pos.x;
								point.y += pos.y;
								point.z += pos.z;
								VFactif = 0.0;



								for (int i = 0; i < 100; i++) {
																float d = distance(vec4(tabcentre[i]+pos.xyz, 1.0), point);

																if (d < tabrayon[i]) {
																								point.xyz = (point.xyz + (1.0 - (d / tabrayon[i])) * tabdef[i].xyz);
																								VFactif = 1.0;
																}


								}

								if (time > 0.f)
								{
																point.z += sin(time) * 3.f;
								}

								gl_Position = gl_ModelViewProjectionMatrix * point;
}
