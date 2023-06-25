for (int i = 0; i < towns_count; i++)
	{
		if (!strcmp(towns[i].name, name))
		{
			return &towns[i];
		}
	}
	return &towns[0];