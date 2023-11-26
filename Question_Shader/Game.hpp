#pragma once

#include"Object.hpp"

struct Game {

	Array<Object> objects;
	PixelShader psWhite;

	void init() {

		psWhite = HLSL{ U"shader/white.hlsl", U"PS" };
		if (not psWhite)
		{
			throw Error{ U"Failed to load a shader file" };
		}


		TextureAsset::Register(U"windmill", U"example/windmill.png");
		TextureAsset::Load(U"windmill");


		for (int i = 0; i < 3; i++) {
			objects.push_back(Object(i * 200));
		}
	}

	void update() {

		for (auto& object : objects) {
			object.update();
		}
	}

	void draw()const {

		for (auto& object : objects) {
			object.draw();
		}
	}

};
