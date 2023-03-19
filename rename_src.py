import os
[os.rename(folder, '_'.join(folder.split())) for folder in [f for f in os.listdir() if os.path.isdir(f)]]