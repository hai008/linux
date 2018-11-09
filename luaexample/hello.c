#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static void stackDump(lua_State*L)
{
	int i;
	int top = lua_gettop(L);
	for(i = 1; i <= top; ++i)
	{
		int t = lua_type(L, i);
		switch(t)
		{
			case LUA_TSTRING:
			{
				printf("'%s'", lua_tostring(L, i));
				break;
			}
			
			case LUA_TBOOLEAN:
			{
				printf(lua_toboolean(L, i) ? "true" : "false");
				break;
			}
			
			case LUA_TNUMBER:
			{
				printf("'%G'", lua_tonumber(L, i));
				break;
			}
			default:
			{
				printf("%s", lua_typename(L, t));
				break;
			}
		}
		printf(" ");
	}
	printf("\n");
}

void load(lua_State *L, const char *fname, int *w, int *h)
{
	if(luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
	{
		printf("cannot run config");
	}
	lua_getglobal(L, "width");
	lua_getglobal(L, "height");
	if(!lua_isnumber(L, -2))
	{
		printf("width err");
	}
	
	if(!lua_isnumber(L, -1))
	{
		printf("height err");
	}
	
	*w = lua_tointeger(L, -2);
	*h = lua_tointeger(L, -1);
	
}

int main()
{
	lua_State *L = luaL_newstate();
	/*lua_pushboolean(L, 1);
	lua_pushnumber(L, 10);
	lua_pushnil(L);
	lua_pushstring(L, "hello");
	
	stackDump(L);*/
	int w, h;
	load(L, "/home/l/lua/c/wh.lua", &w, &h);
	printf("w:%d  h:%d\n", w, h);
}
/*
int main()
{
	
	char buff[256];
	int error ;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	while(fgets(buff, sizeof(buff), stdin) != NULL)
	{
		error = luaL_loadbuffer(L, buff, strlen(buff), "line") || lua_pcall(L, 0, 0, 0);
		if(error)
		{
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}
	lua_close(L);
	return 0;
}*/