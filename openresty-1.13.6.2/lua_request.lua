--ngx.say("hello world");
--[[
local arg=ngx.req.get_uri_args()
for k,v in pairs(arg) do
	ngx.say("[get] key:", k , " v:", v)
end

ngx.req.read_body()
local arg=ngx.req.get_post_args()
for k,v in pairs(arg) do
ngx.say("[post] key:", k, " v:", v)
end
]]

local mysql = require "resty.mysql"

local db = mysql:new()
local ok, err, errcode, sqlstate = db:connect({
        host = "119.29.141.207",
        port = 3306,
        database = "recycle",
        user = "hjx",
        password = "123456"})
if not ok then
    ngx.say("failed to connect: ", err, ": ", errcode, " ", sqlstate)
    return
end
local res, err, errcode, sqlstate =
    db:query("select sleep(10) from t_order limit 1")

if not res then
    ngx.say("bad result: ", err, ": ", errcode, ": ", sqlstate, ".")
    return
end

local cjson = require "cjson"

--os.execute("sleep " .. 10)

ngx.say("result: ", cjson.encode(res))
