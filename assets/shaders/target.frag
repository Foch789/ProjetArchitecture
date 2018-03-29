varying float VFactif;

uniform sampler2D tex;

void main (void)
{

        vec4 sum = vec4(0.0);
        if (VFactif == 0.0)
        {

                sum = texture2D(tex, gl_TexCoord[0].st);

        }
        else
        {
                sum = vec4(1.0,0.0,0.0,1.0);
        }

        gl_FragColor = sum;
}
