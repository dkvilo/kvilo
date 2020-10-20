local macro = {}

-- This macro reads ssh key value from collection tinyhoods.net and passes to ssh command
-- macro.ssh = "ssh `kvilo get mycollection myserver_auth_info`"

-- Custom Message
macro.message = "echo 'Pong'"


boot = function()

  -- Register custom macro
  -- if kvilo.arg1 == "ssh" and kvilo.arg2 == "tinyhoods" then
  --   return macro.ssh
  -- end

  if kvilo.arg1 == "ping" then
    return macro.message
  end

end
