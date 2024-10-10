local md5 = require 'common.lua.md5'
local redisModule = require 'common.lua.redis'
local args = ngx.var.args
local uri = ngx.var.uri

local redis = redisModule.connect()
if redis == nil then
    ngx.exit(ngx.HTTP_INTERNAL_SERVER_ERROR)
end

local key = 'page_type:' .. md5.sumhexa(uri)
local val = redis:get(key)

if type(val) == 'string' then
    -- если в сохраненной строке есть ?
    local pos = string.find(val, '?')
    if pos then
        -- нужно разделить строку на аргументы и адрес
        args = string.sub(val, pos + 1) .. '&' .. args
        val = string.sub(val, 1, pos - 1)
    end
    uri = 'plp' .. val
else
    uri = 'pdp' .. uri
end

if args then
    uri = uri .. '?' .. args
end

uri = '/catalog/' .. uri

--ngx.say(uri)
ngx.exec(uri)
