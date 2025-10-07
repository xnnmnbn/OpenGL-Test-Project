#pragma once

#include <entt/entt.hpp>

namespace gdl {

class GameObject{
private:
	entt::entity id;
	entt::registry* reg;

public:

	GameObject(entt::registry& reg);

	template<typename T, typename... Args>
	inline GameObject*& add_component(Args&&... args){
		reg->emplace<T>(id, std::forward<Args>(args)...);

		return (this);
	}

	template<typename T>
	inline GameObject*& remove_component(){
		reg->remove<T>(id);

		return this;
	}

	template<typename T>
	inline T& get_component(){
		return reg->get<T>(id);
	}

};



}






