import requests
link2 = "https://erp.mitwpu.edu.in/CBCS/Application.aspx"
response = requests.get(link2)
count = 0
while response.status_code != 200:
    response = requests.get(link2)
    count+=1
    print(count, response.status_code)
