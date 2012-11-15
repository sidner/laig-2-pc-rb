uniform sampler2D baseTexture;
uniform sampler2D secTexture;



void main(void)
{	float neve;
    vec4 cor= texture2D(baseTexture, gl_TexCoord[0].st);
    vec4 offset = texture2D(secTexture, gl_TexCoord[0].st);
		
	neve = 5.0*offset.r+5.0*offset.g+5.0*offset.b;
 	if(neve>10.0){
		gl_FragColor = vec4(0.9,0.9,0.9,3);
}else{
 gl_FragColor = cor;
}
    //set the output color
   
}
