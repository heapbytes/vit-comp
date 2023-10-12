FROM python:3.8-slim

WORKDIR /app

COPY app.py /app
RUN mkdir -p app/templates

COPY templates/index.html /app/templates/

#COPY requirements.txt /app
#RUN ls -laR

RUN pip install flask --break-system-packages

EXPOSE 5000
CMD ["python", "app.py"]

