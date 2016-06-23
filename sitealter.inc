<?php
function json_format()
{
	return drupal_get_form('json_format_setting');
}
function json_format_setting($form,&$form_state)
{
	if(variable_get("siteapikey", $default = NULL)!='')
	{
		$node_info=node_load(arg(2));
		
		if($node_info->type=="page")
		{
			print json_encode(node_load(arg(2)));
			exit;
		}
		else
		{
			drupal_access_denied();
		}
		
	}
	else
	{
		drupal_access_denied();
	}
}