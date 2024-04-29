import pickle
import pandas as pd
import sys
from model import DQN
import torch

print('Loading model...')
model = DQN()
model.load_state_dict(torch.load('rlEngine/model.pth'))
print('Model loaded successfully')
print('Loading data...')
input_filename = sys.argv[1]
data = pd.read_csv(input_filename, delimiter=',', header=None)
data = torch.tensor(data.values, dtype=torch.float32)
data = data.unsqueeze(0).unsqueeze(1)
print(f'data shape: {data.shape}')
print('Data loaded successfully')
print('Predicting...')
predictions = model(data)
print("predictions shape: ", predictions.shape)
predictions = predictions.squeeze().detach().numpy()
print(f'predictions shape: {predictions.shape}')
output_filename = sys.argv[2]
pd.DataFrame(predictions).to_csv(output_filename, index=False, header=False)
print('Predictions saved to', output_filename)
