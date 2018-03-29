varying float VFactif; //oh tient, on reçoit une valeur de type float de la part du vertex shader

void main (void)
{

        if (VFactif == 0.0)
        {
                //gl_FragColor = vec4(0.0,0.0,1.0,1.0);
                gl_FragColor = gl_Color;
        }
        else
        {
                //gl_FragColor = vec4(1.0,0.0,0.0,1.0);                //"modif" de tous les pixels (bleu) pour l'instant

        }


}
