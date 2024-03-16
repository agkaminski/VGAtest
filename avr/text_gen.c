#include <stdint.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>


static const uint16_t string[] PROGMEM = {
	0x6f4d, 0x206a, 0x7473, 0x7261, 0x2079, 0x6f74, 0x6620, 0x6e61, 
	0x7461, 0x6b79, 0x7720, 0x6465, 0x616b, 0x7372, 0x7774, 0x2e61, 
	0x5020, 0x6c6f, 0x6d20, 0x6569, 0x7a73, 0x616b, 0x696e, 0x2061, 
	0x617a, 0x656a, 0x6162, 0x656e, 0x7720, 0x6465, 0x616b, 0x696d, 
	0x6e20, 0x6a61, 0x6f67, 0x7372, 0x657a, 0x202e, 0x730a, 0x6572, 
	0x6e64, 0x6f69, 0x7220, 0x7a61, 0x7720, 0x6d20, 0x6569, 0x6973, 
	0x6361, 0x2075, 0x746b, 0x736f, 0x7720, 0x6564, 0x6e70, 0x6569, 
	0x7720, 0x6c20, 0x7a65, 0x6361, 0x2079, 0x616e, 0x7a20, 0x6569, 
	0x696d, 0x6820, 0x6361, 0x797a, 0x206b, 0x7a63, 0x2079, 0x6f6b, 
	0x7774, 0x6369, 0x2065, 0x0a69, 0x7274, 0x657a, 0x6162, 0x7720, 
	0x6379, 0x6169, 0x6167, 0x2063, 0x2077, 0x7a73, 0x6970, 0x6174, 
	0x756c, 0x6220, 0x206f, 0x616d, 0x616a, 0x7a20, 0x6461, 0x697a, 
	0x726f, 0x2079, 0x616e, 0x6b20, 0x6e6f, 0x7563, 0x202e, 0x2057, 
	0x7773, 0x696f, 0x206d, 0x3232, 0x6c20, 0x7465, 0x696e, 0x206d, 
	0x797a, 0x6963, 0x0a75, 0x756a, 0x207a, 0x207a, 0x3031, 0x7220, 
	0x7a61, 0x2079, 0x7962, 0x656c, 0x206d, 0x616e, 0x7420, 0x6b61, 
	0x6d69, 0x7a20, 0x6261, 0x6569, 0x7567, 0x202e, 0x7954, 0x7a64, 
	0x6569, 0x206e, 0x6574, 0x756d, 0x7020, 0x736f, 0x657a, 0x6c64, 
	0x6d65, 0x6e20, 0x2061, 0x616a, 0x696b, 0x7365, 0x6c20, 0x736f, 
	0x776f, 0x0a65, 0x6162, 0x6164, 0x696e, 0x2061, 0x6f74, 0x6220, 
	0x6261, 0x2061, 0x207a, 0x6572, 0x6563, 0x6370, 0x696a, 0x6a20, 
	0x6b61, 0x6d20, 0x696e, 0x2065, 0x7974, 0x6b6c, 0x206f, 0x6f7a, 
	0x6162, 0x7a63, 0x6c79, 0x2061, 0x6f74, 0x6b20, 0x7a61, 0x6c61, 
	0x2061, 0x7562, 0x6174, 0x7320, 0x6963, 0x6761, 0x6361, 0x7820, 
	0x0a44, 0x6f62, 0x6d20, 0x7379, 0x616c, 0x616c, 0x202c, 0x657a, 
	0x7a20, 0x6f6e, 0x7577, 0x6820, 0x6b61, 0x7720, 0x6e20, 0x646f, 
	0x657a, 0x442e, 0x7572, 0x6167, 0x7020, 0x6c6f, 0x776f, 0x2061, 
	0x696d, 0x7365, 0x6b7a, 0x6e61, 0x6169, 0x7a20, 0x6a61, 0x6265, 
	0x6e61, 0x2061, 0x6557, 0x6b64, 0x7261, 0x657a, 0x0a6d, 0x6f50, 
	0x736c, 0x696b, 0x2c6d, 0x7320, 0x6977, 0x7461, 0x6d65, 0x5720, 
	0x6465, 0x616b, 0x7a72, 0x2c61, 0x5320, 0x7075, 0x7265, 0x4b20, 
	0x7261, 0x6970, 0x6d65, 0x7820, 0x2044, 0x7469, 0x2e70, 0x4320, 
	0x206f, 0x7974, 0x7a64, 0x6569, 0x206e, 0x6a6f, 0x6963, 0x6365, 
	0x7220, 0x626f, 0x2069, 0x626f, 0x616a, 0x647a, 0x700a, 0x206f, 
	0x7377, 0x797a, 0x7473, 0x696b, 0x6863, 0x6b20, 0x6f69, 0x6b73, 
	0x6361, 0x2068, 0x2077, 0x696d, 0x7365, 0x6963, 0x2c65, 0x7a20, 
	0x6265, 0x2079, 0x6b73, 0x6d6f, 0x6c70, 0x7465, 0x776f, 0x6361, 
	0x7720, 0x7a73, 0x7379, 0x6b74, 0x6569, 0x7720, 0x6465, 0x616b, 
	0x7372, 0x696b, 0x0a65, 0x7974, 0x6f67, 0x6e64, 0x6b69, 0x2e69, 
	0x4220, 0x6c79, 0x6d65, 0x6e20, 0x2061, 0x7974, 0x656c, 0x6720, 
	0x756c, 0x6970, 0x202c, 0x657a, 0x6e20, 0x7561, 0x7a63, 0x6c79, 
	0x6d65, 0x6720, 0x206f, 0x6e69, 0x6f74, 0x6920, 0x746e, 0x7265, 
	0x656e, 0x7974, 0x6220, 0x206f, 0x796d, 0x6c73, 0x6c61, 0x6d65, 
	0x202c, 0x657a, 0x740a, 0x6f72, 0x6863, 0x2065, 0x6970, 0x6e65, 
	0x6569, 0x7a64, 0x2079, 0x617a, 0x736f, 0x637a, 0x657a, 0x7a64, 
	0x6d69, 0x2079, 0x616e, 0x7420, 0x6379, 0x2068, 0x6167, 0x657a, 
	0x6b74, 0x6361, 0x2068, 0x6c61, 0x2065, 0x6574, 0x6172, 0x207a, 
	0x696e, 0x2065, 0x6f64, 0x7973, 0x2c63, 0x7a20, 0x2065, 0x656a, 
	0x6b0a, 0x7075, 0x6a75, 0x2065, 0x6f74, 0x6a20, 0x7365, 0x637a, 
	0x657a, 0x7320, 0x6569, 0x7a64, 0x2069, 0x616e, 0x6a20, 0x6b61, 
	0x6369, 0x7368, 0x6620, 0x726f, 0x6361, 0x2068, 0x6c64, 0x2061, 
	0x6577, 0x6b64, 0x7261, 0x797a, 0x6920, 0x6b20, 0x6572, 0x6963, 
	0x6720, 0x776f, 0x6f6e, 0x7562, 0x7a72, 0x2065, 0x0a7a, 0x6e69, 
	0x796e, 0x696d, 0x7720, 0x6465, 0x616b, 0x7a72, 0x6d61, 0x2069, 
	0x206f, 0x616e, 0x6c6a, 0x7065, 0x7a73, 0x2065, 0x617a, 0x656e, 
	0x7974, 0x6920, 0x7074, 0x202e, 0x6f50, 0x7274, 0x6661, 0x2069, 
	0x7264, 0x657a, 0x2063, 0x6f6d, 0x6472, 0x2065, 0x6f64, 0x6d20, 
	0x6e6f, 0x7469, 0x726f, 0x2061, 0x6c61, 0x6f62, 0x770a, 0x7079, 
	0x6569, 0x6472, 0x6c6f, 0x6369, 0x6b20, 0x616c, 0x6977, 0x7461, 
	0x7275, 0x2065, 0x617a, 0x6f20, 0x6e6b, 0x2e6f, 0x4b20, 0x6569, 
	0x7964, 0x2073, 0x6a6f, 0x6963, 0x6365, 0x6d20, 0x696e, 0x2065, 
	0x6b77, 0x7275, 0x6977, 0x206c, 0x6f74, 0x7a20, 0x6c61, 0x7a6f, 
	0x6c79, 0x6d65, 0x7420, 0x6d61, 0x6b0a, 0x6e6f, 0x6f74, 0x6920, 
	0x6720, 0x206f, 0x7274, 0x6c6f, 0x776f, 0x6c61, 0x6d65, 0x7020, 
	0x7369, 0x617a, 0x2063, 0x2077, 0x656a, 0x6f67, 0x7420, 0x6d65, 
	0x7461, 0x6361, 0x2068, 0x616a, 0x696b, 0x7365, 0x6c20, 0x736f, 
	0x776f, 0x2065, 0x6c67, 0x7075, 0x746f, 0x2079, 0x7974, 0x7570, 
	0x6b0a, 0x7261, 0x7361, 0x6569, 0x6a20, 0x6465, 0x6f7a, 0x6720, 
	0x7775, 0x6f6e, 0x202e, 0x614d, 0x6b74, 0x2061, 0x696e, 0x2065, 
	0x616e, 0x6164, 0x617a, 0x616c, 0x7a20, 0x6720, 0x746f, 0x776f, 
	0x6e61, 0x6569, 0x206d, 0x6962, 0x6f67, 0x7573, 0x6e20, 0x2061, 
	0x7375, 0x6f70, 0x6f6b, 0x656a, 0x696e, 0x2e65, 0x410a, 0x6168, 
	0x202c, 0x616d, 0x6a20, 0x7a75, 0x6e20, 0x2061, 0x6f66, 0x7572, 
	0x206d, 0x6172, 0x676e, 0x2065, 0x5553, 0x2c4d, 0x7a20, 0x2061, 
	0x616e, 0x656a, 0x6162, 0x696e, 0x2065, 0x3031, 0x206b, 0x6f70, 
	0x7473, 0x776f, 0x222e, 0x2220, 0x614a, 0x206b, 0x656a, 0x7473, 
	0x6320, 0x6569, 0x6c70, 0x206f, 0x6f74, 0x630a, 0x206f, 0x6577, 
	0x6b65, 0x6e65, 0x2064, 0x617a, 0x6970, 0x7265, 0x6164, 0x616c, 
	0x6e20, 0x2061, 0x7972, 0x7962, 0x202e, 0x644f, 0x6a20, 0x6b61, 
	0x6369, 0x7368, 0x3520, 0x6c20, 0x7461, 0x7720, 0x6b20, 0x7a61, 
	0x6164, 0x6e20, 0x6569, 0x7a64, 0x6569, 0x656c, 0x6a20, 0x6d65, 
	0x7220, 0x6279, 0x2065, 0x616e, 0x6f0a, 0x6962, 0x6461, 0x6120, 
	0x6f20, 0x636a, 0x6569, 0x2063, 0x6970, 0x7265, 0x6f64, 0x696c, 
	0x6f20, 0x7a20, 0x6c61, 0x7465, 0x6361, 0x2068, 0x656a, 0x7a64, 
	0x6e65, 0x6169, 0x7420, 0x6765, 0x206f, 0x6f77, 0x6e64, 0x6765, 
	0x206f, 0x6f67, 0x6e77, 0x2e61, 0x4a20, 0x6b61, 0x7320, 0x6569, 
	0x640a, 0x736f, 0x6174, 0x656c, 0x206d, 0x616e, 0x7320, 0x7574, 
	0x6964, 0x2061, 0x6f74, 0x7320, 0x6174, 0x7972, 0x7020, 0x7a72, 
	0x7a65, 0x7420, 0x6479, 0x697a, 0x6e65, 0x7020, 0x6569, 0x2a2a, 
	0x6c6f, 0x6c69, 0x7a20, 0x2065, 0x6f74, 0x6420, 0x697a, 0x6b65, 
	0x2069, 0x6574, 0x756d, 0x202c, 0x657a, 0x6a20, 0x6d65, 0x640a, 
	0x7a75, 0x206f, 0x7972, 0x2062, 0x6f62, 0x7a20, 0x7761, 0x6569, 
	0x6172, 0x616a, 0x6620, 0x736f, 0x6f66, 0x2072, 0x2069, 0x6f6d, 
	0x677a, 0x6d20, 0x2069, 0x656c, 0x6970, 0x6a65, 0x7020, 0x6172, 
	0x7563, 0x656a, 0x202e, 0x6f43, 0x7320, 0x626f, 0x746f, 0x2065, 
	0x7562, 0x7a64, 0x2069, 0x657a, 0x730a, 0x6f77, 0x6d69, 0x7a20, 
	0x616e, 0x6f6a, 0x796d, 0x206d, 0x696d, 0x6b72, 0x6569, 0x206d, 
	0x6163, 0x616c, 0x7220, 0x646f, 0x697a, 0x656e, 0x6f20, 0x3420, 
	0x7720, 0x6e20, 0x636f, 0x2079, 0x6f62, 0x6820, 0x6c61, 0x7361, 
	0x6a75, 0x2061, 0x6170, 0x756b, 0x616a, 0x2063, 0x6577, 0x6b64, 
	0x2c69, 0x720a, 0x626f, 0x6169, 0x2063, 0x616b, 0x616e, 0x6b70, 
	0x2069, 0x7469, 0x2e64, 0x5020, 0x7a72, 0x2079, 0x656a, 0x7a64, 
	0x6e65, 0x7569, 0x7a20, 0x7761, 0x7a73, 0x2065, 0x6970, 0x7265, 
	0x6f64, 0x696c, 0x6f20, 0x7220, 0x6279, 0x6361, 0x2068, 0x2069, 
	0x617a, 0x6b20, 0x7a61, 0x7964, 0x206d, 0x6172, 0x657a, 0x0a6d, 
	0x6574, 0x616d, 0x2074, 0x6373, 0x6f68, 0x7a64, 0x2069, 0x2077, 
	0x6f6b, 0x636e, 0x2075, 0x616e, 0x5020, 0x6c6f, 0x6b73, 0x2069, 
	0x775a, 0x6169, 0x657a, 0x206b, 0x6557, 0x6b64, 0x7261, 0x6b73, 
	0x2c69, 0x6f20, 0x636a, 0x6569, 0x2063, 0x6173, 0x206d, 0x6973, 
	0x2065, 0x616e, 0x726b, 0x6365, 0x2061, 0x0a69, 0x6f64, 0x7473, 
	0x6a61, 0x2065, 0x7473, 0x6172, 0x7a73, 0x656e, 0x6f67, 0x6220, 
	0x6c6f, 0x2075, 0x7564, 0x7970, 0x6420, 0x7275, 0x2072, 0x696e, 
	0x6465, 0x736f, 0x6174, 0x6574, 0x7a63, 0x696e, 0x2065, 0x617a, 
	0x7972, 0x6962, 0x6a61, 0x206f, 0x7974, 0x6b6c, 0x206f, 0x726b, 
	0x6461, 0x6f6e, 0x6820, 0x7275, 0x2c72, 0x720a, 0x626f, 0x2069, 
	0x6973, 0x2065, 0x7270, 0x797a, 0x7420, 0x6d79, 0x6320, 0x6c61, 
	0x2079, 0x7a63, 0x7265, 0x6f77, 0x796e, 0x6920, 0x6f20, 0x6364, 
	0x6f68, 0x7a64, 0x2069, 0x646f, 0x7320, 0x6f74, 0x756c, 0x6b20, 
	0x6e6c, 0x6361, 0x6920, 0x6920, 0x7a64, 0x6569, 0x6320, 0x797a, 
	0x6174, 0x0a63, 0x6957, 0x6c65, 0x616b, 0x4520, 0x636e, 0x6b79, 
	0x6f6c, 0x6570, 0x6964, 0x2065, 0x7952, 0x2062, 0x7a52, 0x6365, 
	0x6e7a, 0x6379, 0x2068, 0x657a, 0x7962, 0x7320, 0x6569, 0x7520, 
	0x7073, 0x6b6f, 0x696f, 0x2e63, 0x5720, 0x7420, 0x6d79, 0x7220, 
	0x6b6f, 0x2075, 0x6173, 0x206d, 0x6f73, 0x6962, 0x0a65, 0x756b, 
	0x6970, 0x206c, 0x616e, 0x7320, 0x6977, 0x7465, 0x2061, 0x6f70, 
	0x746e, 0x6e6f, 0x202e, 0x634f, 0x797a, 0x6977, 0x6373, 0x6569, 
	0x6420, 0x206f, 0x6977, 0x6967, 0x696c, 0x2069, 0x696e, 0x2065, 
	0x7977, 0x7274, 0x797a, 0x616d, 0x206c, 0x7974, 0x6b6c, 0x206f, 
	0x756a, 0x207a, 0x6377, 0x6f7a, 0x6172, 0x0a6a, 0x6f67, 0x7220, 
	0x7a6f, 0x6170, 0x6f6b, 0x6177, 0x206c, 0x2069, 0x616e, 0x6d64, 
	0x6375, 0x6168, 0x206c, 0x2077, 0x7564, 0x797a, 0x206d, 0x6f70, 
	0x6f6b, 0x756a, 0x202e, 0x6255, 0x6172, 0x206c, 0x6973, 0x2065, 
	0x2077, 0x6574, 0x206e, 0x7773, 0x6a6f, 0x6320, 0x6c61, 0x2079, 
	0x7473, 0x6f72, 0x0a6a, 0x6577, 0x6b64, 0x7261, 0x6b73, 0x2069, 
	0x2069, 0x6973, 0x6465, 0x697a, 0x6c61, 0x6320, 0x6c61, 0x2079, 
	0x7a64, 0x6569, 0x206e, 0x2077, 0x7974, 0x206d, 0x6f70, 0x746e, 
	0x6e6f, 0x6569, 0x6e20, 0x2061, 0x7273, 0x646f, 0x756b, 0x6d20, 
	0x6569, 0x7a73, 0x616b, 0x696e, 0x2e61, 0x4f20, 0x6962, 0x6461, 
	0x280a, 0x616b, 0x7072, 0x2029, 0x6574, 0x207a, 0x2077, 0x696e, 
	0x206d, 0x6a7a, 0x6461, 0x2e6c, 0x4720, 0x7964, 0x7962, 0x206d, 
	0x6e6d, 0x6569, 0x6e20, 0x2061, 0x6c64, 0x6775, 0x736f, 0x2063, 
	0x6572, 0x696b, 0x6420, 0x706f, 0x7375, 0x6963, 0x696c, 0x6420, 
	0x206f, 0x7377, 0x797a, 0x7473, 0x696b, 0x6863, 0x720a, 0x6279, 
	0x7720, 0x7020, 0x6c6f, 0x6373, 0x2065, 0x6f74, 0x6220, 0x6d79, 
	0x7720, 0x697a, 0x6c61, 0x6920, 0x7a20, 0x7061, 0x6569, 0x6472, 
	0x6c6f, 0x6c69, 0x202e, 0x614a, 0x206b, 0x746b, 0x726f, 0x6765, 
	0x736f, 0x7220, 0x7a61, 0x2c75, 0x6a20, 0x7365, 0x637a, 0x657a, 
	0x7720, 0x7020, 0x646f, 0x6162, 0x697a, 0x0a65, 0x7a63, 0x2079, 
	0x6967, 0x626d, 0x7a61, 0x6569, 0x202c, 0x696d, 0x6c61, 0x6d65, 
	0x7520, 0x6f72, 0x7a64, 0x6e69, 0x2079, 0x6f74, 0x7320, 0x6174, 
	0x7972, 0x6a20, 0x6b61, 0x206f, 0x7270, 0x7a65, 0x6e65, 0x2074, 
	0x7a77, 0x6169, 0x206c, 0x6e6d, 0x6569, 0x7a20, 0x2065, 0x6f73, 
	0x6162, 0x6e20, 0x2061, 0x7972, 0x7962, 0x770a, 0x6420, 0x6f72, 
	0x7a64, 0x2065, 0x7977, 0x616a, 0x6b74, 0x2e75, 0x5320, 0x7075, 
	0x7265, 0x7020, 0x6572, 0x657a, 0x746e, 0x6b20, 0x7275, 0x6f77, 
	0x202e, 0x6f50, 0x656a, 0x6863, 0x6c61, 0x7369, 0x796d, 0x6720, 
	0x7a64, 0x6569, 0x2073, 0x7077, 0x7a69, 0x7564, 0x7a20, 0x2061, 
	0x696d, 0x7361, 0x6f74, 0x0a2c, 0x6f64, 0x6863, 0x646f, 0x697a, 
	0x796d, 0x6e20, 0x6461, 0x6a20, 0x7a65, 0x6f69, 0x6f72, 0x6120, 
	0x6f20, 0x636a, 0x2075, 0x756a, 0x207a, 0x6973, 0x2065, 0x636f, 
	0x797a, 0x7320, 0x6977, 0x6365, 0x2061, 0x2069, 0x626f, 0x696c, 
	0x757a, 0x656a, 0x7720, 0x7261, 0x6967, 0x7020, 0x646f, 0x696e, 
	0x6365, 0x6e6f, 0x2e79, 0x520a, 0x7a6f, 0x6f6c, 0x797a, 0x206c, 
	0x6163, 0x796c, 0x7320, 0x7270, 0x657a, 0x2074, 0x2069, 0x6973, 
	0x6465, 0x697a, 0x796d, 0x6e20, 0x6461, 0x7720, 0x646f, 0x2061, 
	0x2069, 0x6170, 0x7274, 0x797a, 0x796d, 0x6e20, 0x2061, 0x7073, 
	0x616c, 0x6977, 0x696b, 0x202e, 0x6f50, 0x7020, 0x6569, 0x6963, 
	0x0a75, 0x696d, 0x756e, 0x6174, 0x6863, 0x6d20, 0x2069, 0x6973, 
	0x2065, 0x6e7a, 0x6475, 0x697a, 0x6f6c, 0x7720, 0x6569, 0x2063, 
	0x6c77, 0x6361, 0x797a, 0x656c, 0x206d, 0x6964, 0x6373, 0x616d, 
	0x616e, 0x7420, 0x206f, 0x6e6d, 0x6569, 0x6f20, 0x636a, 0x6569, 
	0x2063, 0x6970, 0x7265, 0x6f64, 0x6e6c, 0x6c61, 0x770a, 0x6465, 
	0x616b, 0x7020, 0x206f, 0x6c67, 0x776f, 0x6569, 0x202c, 0x657a, 
	0x7220, 0x6279, 0x2079, 0x6c73, 0x7379, 0x617a, 0x6d20, 0x7a75, 
	0x6b79, 0x2065, 0x207a, 0x6f6d, 0x6369, 0x2068, 0x6c73, 0x6375, 
	0x6168, 0x6577, 0x206b, 0x2069, 0x6973, 0x2065, 0x6c70, 0x736f, 
	0x617a, 0x202e, 0x614a, 0x206b, 0x6973, 0x0a65, 0x6863, 0x6963, 
	0x6c61, 0x6d65, 0x7020, 0x646f, 0x6172, 0x6170, 0x2063, 0x6f70, 
	0x6420, 0x7075, 0x6569, 0x7420, 0x206f, 0x617a, 0x6172, 0x207a, 
	0x6b27, 0x7a72, 0x6379, 0x617a, 0x206c, 0x7a73, 0x7065, 0x6574, 
	0x276d, 0x202c, 0x657a, 0x7962, 0x206d, 0x6973, 0x2065, 0x696e, 
	0x2065, 0x6977, 0x7265, 0x6963, 0x0a6c, 0x6f62, 0x7320, 0x657a, 
	0x656c, 0x7a73, 0x7a63, 0x2065, 0x2069, 0x7972, 0x7962, 0x7a20, 
	0x7720, 0x646f, 0x2079, 0x6977, 0x7a64, 0x2061, 0x616a, 0x206b, 
	0x6973, 0x2065, 0x7572, 0x7a73, 0x6d61, 0x6920, 0x7520, 0x6963, 
	0x6b65, 0x6a61, 0x2e61, 0x3620, 0x6720, 0x646f, 0x697a, 0x206e, 
	0x756d, 0x6973, 0x6c61, 0x6d65, 0x730a, 0x6569, 0x7a64, 0x6569, 
	0x2063, 0x2077, 0x6562, 0x727a, 0x6375, 0x7568, 0x6920, 0x7020, 
	0x7461, 0x7a72, 0x6365, 0x6e20, 0x2061, 0x6f77, 0x6564, 0x6a20, 
	0x6b61, 0x7720, 0x6a20, 0x6b61, 0x6d69, 0x2073, 0x656a, 0x6162, 
	0x796e, 0x206d, 0x7547, 0x6e61, 0x6174, 0x616e, 0x6f6d, 0x0a2e, 
	0x7255, 0x646f, 0x697a, 0x796e, 0x6d20, 0x6d61, 0x7720, 0x6c20, 
	0x7369, 0x6f74, 0x6170, 0x7a64, 0x6569, 0x7720, 0x6569, 0x2063, 
	0x656a, 0x7a73, 0x7a63, 0x2065, 0x6f64, 0x7420, 0x6765, 0x206f, 
	0x7962, 0x6f6c, 0x7a20, 0x6d69, 0x6f6e, 0x6a20, 0x6b61, 0x7320, 
	0x6d61, 0x7320, 0x756b, 0x7772, 0x7379, 0x6e79, 0x0a2e, 0x2057, 
	0x6570, 0x6e77, 0x6d79, 0x6d20, 0x6d6f, 0x6e65, 0x6963, 0x2065, 
	0x6a6f, 0x6963, 0x6365, 0x6f20, 0x7364, 0x657a, 0x6c64, 0x6b20, 
	0x6c69, 0x616b, 0x616e, 0x6373, 0x6569, 0x6d20, 0x7465, 0x6f72, 
	0x2077, 0x2077, 0x616c, 0x2073, 0x2069, 0x6973, 0x2065, 0x7073, 
	0x6569, 0x6472, 0x697a, 0x6c61, 0x0a2e, 0x7957, 0x6c74, 0x6d75, 
	0x6361, 0x797a, 0x206c, 0x696d, 0x202c, 0x657a, 0x7420, 0x7a72, 
	0x6265, 0x2061, 0x2077, 0x656c, 0x6973, 0x2065, 0x6970, 0x7265, 
	0x7a64, 0x6569, 0x2063, 0x6f62, 0x6920, 0x616e, 0x7a63, 0x6a65, 
	0x7220, 0x6279, 0x2079, 0x6c73, 0x7379, 0x617a, 0x6920, 0x6320, 
	0x757a, 0x616a, 0x0a2e, 0x7357, 0x6f70, 0x6e6d, 0x6169, 0x656c, 
	0x2c6d, 0x7a20, 0x2065, 0x6a6f, 0x6963, 0x6365, 0x6d20, 0x2061, 
	0x6f6b, 0x656c, 0x6567, 0x6d20, 0x7269, 0x616b, 0x202c, 0x207a, 
	0x746b, 0x726f, 0x6d79, 0x6a20, 0x7a65, 0x7a64, 0x2069, 0x616e, 
	0x7220, 0x6279, 0x2e79, 0x4b20, 0x6569, 0x7964, 0x0a73, 0x6f74, 
	0x6177, 0x7a72, 0x7379, 0x657a, 0x206d, 0x7977, 0x7270, 0x7761, 
	0x7220, 0x6279, 0x796e, 0x6863, 0x6220, 0x6c79, 0x6820, 0x6865, 
	0x2065, 0x625a, 0x7379, 0x657a, 0x2e6b, 0x4320, 0x6c7a, 0x776f, 
	0x6569, 0x206b, 0x206f, 0x736b, 0x747a, 0x6c61, 0x6963, 0x2065, 
	0x6970, 0x6b6c, 0x2069, 0x0a7a, 0x6177, 0x6573, 0x206d, 0x2069, 
	0x3633, 0x2035, 0x6e64, 0x2069, 0x2077, 0x6f72, 0x756b, 0x7720, 
	0x6b20, 0x6d61, 0x7a69, 0x6c65, 0x6563, 0x4220, 0x4d4f, 0x4542, 
	0x2e52, 0x4220, 0x6c79, 0x2069, 0x207a, 0x6f6d, 0x6d69, 0x6f20, 
	0x636a, 0x6d65, 0x7020, 0x6172, 0x6977, 0x2065, 0x616a, 0x0a6b, 
	0x7262, 0x6361, 0x6169, 0x202c, 0x7270, 0x797a, 0x6863, 0x646f, 
	0x697a, 0x206c, 0x207a, 0x6f7a, 0x616e, 0x4220, 0x7a6f, 0x6e65, 
	0x2061, 0x616e, 0x7720, 0x6769, 0x6c69, 0x6569, 0x6420, 0x206f, 
	0x616e, 0x2073, 0x7469, 0x2e64, 0x5220, 0x7a61, 0x6f20, 0x636a, 
	0x6569, 0x2063, 0x696d, 0x6c61, 0x690a, 0x696d, 0x6e65, 0x6e69, 
	0x2079, 0x627a, 0x7379, 0x6f69, 0x7020, 0x7a72, 0x7379, 0x657a, 
	0x6c64, 0x6e20, 0x2061, 0x6568, 0x6568, 0x6b20, 0x6569, 0x696c, 
	0x6863, 0x2e61, 0x4e20, 0x6a61, 0x6265, 0x6c61, 0x2069, 0x6973, 
	0x2065, 0x2069, 0x636f, 0x797a, 0x6977, 0x6373, 0x6569, 0x6320, 
	0x6c61, 0x0a79, 0x7a63, 0x7361, 0x6720, 0x6461, 0x6c61, 0x2069, 
	0x206f, 0x6577, 0x6b64, 0x776f, 0x6e61, 0x7569, 0x6920, 0x7220, 
	0x6279, 0x6361, 0x2e68, 0x4a20, 0x2061, 0x6973, 0x6465, 0x697a, 
	0x6c61, 0x6d65, 0x7520, 0x7320, 0x6569, 0x6962, 0x2065, 0x2077, 
	0x6f70, 0x6f6b, 0x756a, 0x202e, 0x2057, 0x6570, 0x6e77, 0x6d79, 
	0x6d0a, 0x6d6f, 0x6e65, 0x6963, 0x2065, 0x617a, 0x7a63, 0x6c65, 
	0x2069, 0x7264, 0x657a, 0x2063, 0x616e, 0x7320, 0x6569, 0x6962, 
	0x2065, 0x6f6d, 0x6472, 0x2c65, 0x6320, 0x797a, 0x6720, 0x6e65, 
	0x7265, 0x6c61, 0x696e, 0x2065, 0x656c, 0x7370, 0x657a, 0x7320, 
	0x2061, 0x7a73, 0x7a63, 0x7075, 0x6b61, 0x2069, 0x7a63, 0x0a79, 
	0x7573, 0x796d, 0x202e, 0x4557, 0x207a, 0x4e4d, 0x4549, 0x4e20, 
	0x4549, 0x5720, 0x554b, 0x5752, 0x4149, 0x204a, 0x425a, 0x4359, 
	0x5548, 0x202c, 0x4957, 0x5a44, 0x4149, 0x456c, 0x2073, 0x5954, 
	0x4b20, 0x4549, 0x5944, 0x2073, 0x414a, 0x494b, 0x2045, 0x5a53, 
	0x5a43, 0x5055, 0x4b41, 0x4d20, 0x0a41, 0x655a, 0x5942, 0x203f, 
	0x4843, 0x5041, 0x2053, 0x2049, 0x6552, 0x414b, 0x5520, 0x454a, 
	0x4142, 0x414e, 0x2021, 0x554b, 0x5752, 0x2041, 0x4154, 0x4544, 
	0x204b, 0x5553, 0x594d, 0x5720, 0x5020, 0x4c4f, 0x4353, 0x2045, 
	0x4f50, 0x3820, 0x2030, 0x494b, 0x4f4c, 0x5720, 0x7a41, 0x2c61, 
	0x5420, 0x6f57, 0x0a4a, 0x5a53, 0x5a43, 0x5055, 0x4b41, 0x5420, 
	0x204f, 0x4d49, 0x4d20, 0x7a4f, 0x2045, 0x414e, 0x4b53, 0x434f, 
	0x595a, 0x2063, 0x4f43, 0x5420, 0x2059, 0x494d, 0x4f20, 0x5320, 
	0x4d55, 0x4341, 0x2048, 0x4950, 0x5245, 0x4f44, 0x494c, 0x5a53, 
	0x4a20, 0x4b41, 0x4c20, 0x4445, 0x4f57, 0x5520, 0x4c4b, 0x4a45, 
	0x0a65, 0x4f50, 0x5254, 0x4641, 0x5349, 0x205a, 0x205a, 0x4f57, 
	0x5944, 0x5720, 0x4359, 0x6149, 0x4e47, 0x6361, 0x202e, 0x5a53, 
	0x5a43, 0x5055, 0x4b41, 0x5420, 0x204f, 0x454a, 0x5453, 0x4b20, 
	0x6f52, 0x204c, 0x4f57, 0x5944, 0x4a20, 0x4b41, 0x4c20, 0x5745, 
	0x4a20, 0x5345, 0x2054, 0x524b, 0x4c6f, 0x440a, 0x557a, 0x474e, 
	0x494c, 0x4e20, 0x206f, 0x2069, 0x7a61, 0x7320, 0x6569, 0x7a20, 
	0x6361, 0x657a, 0x696c, 0x6e20, 0x6b61, 0x7275, 0x6977, 0x6361, 
	0x7a20, 0x7061, 0x7361, 0x2079, 0x616e, 0x6420, 0x7779, 0x6e61, 
	0x6569, 0x7720, 0x6420, 0x7a75, 0x6d79, 0x7020, 0x6b6f, 0x6a6f, 
	0x2075, 0x2061, 0x616a, 0x7a20, 0x6d0a, 0x7461, 0x616b, 0x6d20, 
	0x7375, 0x6569, 0x696c, 0x6d73, 0x2079, 0x6369, 0x2068, 0x6f72, 
	0x7a64, 0x6569, 0x616c, 0x2e63, 0x4f20, 0x2064, 0x6574, 0x6f67, 
	0x6320, 0x617a, 0x7573, 0x7a20, 0x7075, 0x6c65, 0x696e, 0x2065, 
	0x657a, 0x7772, 0x6c61, 0x2069, 0x6f6b, 0x746e, 0x6b61, 0x2e74, 
	0x5720, 0x7a0a, 0x7365, 0x6c7a, 0x6d79, 0x7220, 0x6b6f, 0x2075, 
	0x617a, 0x7a64, 0x6f77, 0x696e, 0x616c, 0x7a20, 0x6e6f, 0x2061, 
	0x627a, 0x7379, 0x6169, 0x202c, 0x657a, 0x7a20, 0x7962, 0x6973, 
	0x206f, 0x7073, 0x6461, 0x206c, 0x207a, 0x6f72, 0x6577, 0x6b72, 
	0x2061, 0x2069, 0x617a, 0x7270, 0x7361, 0x617a, 0x6e20, 0x0a61, 
	0x6f70, 0x7267, 0x657a, 0x2e62, 0x4f20, 0x6564, 0x7262, 0x6c61, 
	0x2061, 0x6b61, 0x7275, 0x7461, 0x6d20, 0x7461, 0x616b, 0x202c, 
	0x6c7a, 0x7a6f, 0x6c79, 0x2061, 0x6f6b, 0x646e, 0x6c6f, 0x6e65, 
	0x6a63, 0x2c65, 0x6f20, 0x6b64, 0x616c, 0x6164, 0x7320, 0x756c, 
	0x6863, 0x7761, 0x656b, 0x6920, 0x6d20, 0x776f, 0x0a69, 0x206f, 
	0x7974, 0x206d, 0x6a6f, 0x7563, 0x202c, 0x2061, 0x6a6f, 0x6963, 
	0x6365, 0x0a2e, 0x2049, 0x6162, 0x6472, 0x6f7a, 0x6b20, 0x7275, 
	0x6177, 0x6420, 0x626f, 0x7a72, 0x2e65, 0x5420, 0x6b61, 0x6720, 
	0x206f, 0x617a, 0x7420, 0x6765, 0x206f, 0x7573, 0x616d, 0x7a20, 
	0x696e, 0x6e65, 0x7761, 0x6469, 0x697a, 0x2e6c, 0x000a
};


static char getChar(size_t pos)
{
	uint16_t data = pgm_read_word(string + (pos / 2));
	return (pos & 1) ? data >> 8 : data & 0xff;
}


static void setAddr(uint16_t addr)
{
	PORTC = addr & 0xff;
	uint8_t temp = PORTD & ~0x1f;
	PORTD = temp | ((addr >> 8) & 0x1f);
}

static void setData(uint8_t data)
{
	PORTA = data;
}

static void selectROM(int sel)
{
	uint8_t temp = PORTD & ~(0x3 << 6);
	PORTD = temp | ((sel & 0x3) << 6);
}

static void writeByte(uint16_t addr, uint8_t data)
{
	setAddr(addr);
	setData(data);

	PORTB &= ~((1 << 2) | 1);

	_delay_us(100);

	PORTB |= (1 << 2) | 1;
}

static void putChar(int row, int col, char c)
{
	uint16_t addr = (row << 7) + col;
	writeByte(addr, c);
}

static void vsync(void)
{
	while (PINB & (1 << 4));
	while (!(PINB & (1 << 4)));
}

static void clear(void)
{
	for (uint16_t addr = 0; addr < 8192; addr++)
		writeByte(addr, ' ');
}

int main(void)
{
	/* Inactivate control signals */
	DDRB = 0x0f;
	PORTB = 0xff;

	/* Address bus */
	DDRC = 0xff;
	DDRD = 0xff;

	/* Data bus */
	DDRA = 0xff;

	/* Select ROM #0 */
	selectROM(0);

	/* Reset chipset */
	PORTB &= ~(1 << 3);

	/* Clear memory */
	clear();

	/* Release the kraken! */
	PORTB |= 1 << 3;

	int rom = 0;

	while (1) {
		char c;
		int pos = 0;
		int row = 0, col = 0;
		while ((c = getChar(pos++)) != '\0') {
			if (c == '\n') { row++; col = 0; continue; }

			/* Wait for vsync */
			vsync();

			putChar(row, col, c);
			if (++col >= 80) { col = 0; ++row; }
		}

		for (int i = 0; i < 8; ++i)
			_delay_ms(250);

		clear();

		if (++rom > 1) rom = 0;
		selectROM(rom);
	}

	return 0;
}

