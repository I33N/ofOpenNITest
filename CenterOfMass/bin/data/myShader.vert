//#extension GL_EXT_gpu_shader4 : enable

varying vec4 color;

uniform sampler2DRect depth;
uniform sampler2DRect tex;
uniform sampler2DRect user;

uniform vec2 resolution;
uniform vec2 XYtoZ;

void main() {
	//DIRECT MODE
   	//vec4 pos = gl_Vertex;
	//gl_Position = gl_ModelViewProjectionMatrix * pos;
   	
	//DIRECT MODE IN WORLD SPACE
 	//vec4 pos = gl_Vertex;
	//float fNormalizedX = (pos.x / resolution.x - 0.5);
        //pos.x = (fNormalizedX * pos.z * XYtoZ.x);
        //float fNormalizedY = (0.5 - pos.y / resolution.y);
        //pos.y = (fNormalizedY * pos.z * XYtoZ.y);
	//gl_Position = gl_ModelViewProjectionMatrix * pos;
	
	//PROJECTIVE SPACE WITH DEPTH IN TEXTURE
	//vec4 pos = gl_Vertex;
	//pos.z = float(texture2DRect(depth,gl_MultiTexCoord0.xy).x)*65535.0;
	//gl_Position = gl_ModelViewProjectionMatrix * pos;
   	
	//WORLD SPACE WITH DEPTH IN TEXTURE
	//vec4 pos;
	//pos.xy = gl_MultiTexCoord0.xy;
	//pos.z = float(texture2DRect(depth,gl_MultiTexCoord0.xy).x)*65535.0;
	//pos.w = 1.0;
	
	//float fNormalizedX = (pos.x / resolution.x - 0.5);
        //pos.x = (fNormalizedX * pos.z * XYtoZ.x);
        //float fNormalizedY = (0.5 - pos.y / resolution.y);
        //pos.y = (fNormalizedY * pos.z * XYtoZ.y);
	
	//gl_Position = gl_ModelViewProjectionMatrix * pos;

	//USER TRACKING VERSION
	float user = texture2DRect(user, gl_MultiTexCoord0.xy).x;
	if(user>0.0)
		user=1.0;	

	vec4 pos;
	pos.xy = gl_MultiTexCoord0.xy;
	pos.z = float(texture2DRect(depth,gl_MultiTexCoord0.xy).x)*65535.0;
	pos.w = 1.0;
	
	float fNormalizedX = (pos.x / resolution.x - 0.5);
        pos.x = (fNormalizedX * pos.z * XYtoZ.x);
        float fNormalizedY = (0.5 - pos.y / resolution.y);
        pos.y = (fNormalizedY * pos.z * XYtoZ.y);
	
	gl_Position = gl_ModelViewProjectionMatrix * pos * user / 1000;

	color = texture2DRect(tex, gl_MultiTexCoord0.xy) * user;
	//color = texture2DRect(tex, gl_MultiTexCoord0.xy);
} 
