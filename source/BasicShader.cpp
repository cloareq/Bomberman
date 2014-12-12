//
// BasicShader.cpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Tue Jun  3 10:36:48 2014 Antoine BERGHEN
// Last update Tue Jun  3 10:36:51 2014 Antoine BERGHEN
//

#include <BasicShader.hh>

namespace	gdl
{
	BasicShader::BasicShader()
	{
	}


	BasicShader::~BasicShader()
	{
	}

	bool	BasicShader::build()
	{
		bool	ret;
		_build();
		_bindAttribLocation(0, "vPosition");
		_bindAttribLocation(1, "vColor");
		_bindAttribLocation(2, "vNormal");
		_bindAttribLocation(3, "vTexCoord");
		ret = _linkProgram();
		if (ret)
			_bindTextureUnit(0, "fTexture0");
		return (ret);
	}
}
