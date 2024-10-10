local redis_host = os.getenv('REDIS_HOST')
local redis_port = os.getenv('REDIS_PORT')
local redis_pass = os.getenv('REDIS_PASSWORD')
local redis_db = os.getenv('REDIS_DATABASE');
local export = {}

if redis_db == '' then
    redis_db = 0
end

function export.connect()
    local redis = require "resty.redis"
    local red = redis:new()
    local ok, err = red:connect(redis_host, redis_port)

    if err then
        ngx.say(err)
        return nil
    end

    if redis_pass ~= '' then
        local ok, err = red:auth(redis_pass)
        if not ok then
            ngx.say("failed to authenticate: ", err)
            return nil
        end
    end

    red:select(redis_db)

    return red;
end

return export
