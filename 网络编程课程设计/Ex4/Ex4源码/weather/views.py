from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
from weatherCrawler import getWeather
# Create your views here.

def index(request):
	city = request.GET.get('city','')
	if (city):
		rslt = getWeather.main(city)
	else:
		rslt = []
	context = {
		'weatherList': rslt
	}
	return render(request, 'index.html',context = context)