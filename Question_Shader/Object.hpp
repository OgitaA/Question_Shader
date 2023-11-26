#pragma once

#include<Siv3D.hpp>

#include"WhiteEffect.hpp"

struct Object {

	Object(int x) { m_pos = { x,100 }; }

	void update() {

		if (white_count > 0) {
			white_count -= 0.02;
			if (white_count < 0) {
				white_count = 0;
			}
		}

		cbWhite->strength = white_count;
	}


	void draw()const {

		TextureAsset(U"windmill").draw(m_pos);
	}

	ConstantBuffer<WhiteEffectConstants> get_white() { return cbWhite; }





	Vec2 m_pos;
	ConstantBuffer<WhiteEffectConstants> cbWhite;
	float white_count = 0;

};
