#pragma once

#include <entt/entt.hpp>

namespace gdl {

class GameObject{
private:
	entt::entity id;
	entt::registry* reg;

public:

	GameObject(entt::registry& reg, bool add_trans = true, bool add_rend = false);

	template<typename T, typename... Args>
	inline T& add_component(Args&&... args){
		reg->emplace<T>(id, std::forward<Args>(args)...);

		return reg->get<T>(id);
	}

	template<typename T>
	inline void remove_component(){
		reg->remove<T>(id);
	}

	template<typename T>
	inline T& get_component(){
		return reg->get<T>(id);
	}

};



}






