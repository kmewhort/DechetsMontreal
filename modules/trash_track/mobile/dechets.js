window.addEventListener('load', function() {
    window.setTimeout(function() {
	var bubble = new google.bookmarkbubble.Bubble();
	
	var parameter = 'bmb=1';
	
	bubble.hasHashParameter = function() {
	    return window.location.hash.indexOf(parameter) != -1;
	};
	
	bubble.setHashParameter = function() {
	    if (!this.hasHashParameter()) {
		window.location.hash += parameter;
	    }
	};
	
	bubble.getViewportHeight = function() {
	    window.console.log('Example of how to override getViewportHeight.');
	    return window.innerHeight;
	};
	
	bubble.getViewportScrollY = function() {
	    window.console.log('Example of how to override getViewportScrollY.');
	    return window.pageYOffset;
	};
	
	bubble.registerScrollHandler = function(handler) {
	    window.console.log('Example of how to override registerScrollHandler.');
	    window.addEventListener('scroll', handler, false);
	};
	
	bubble.deregisterScrollHandler = function(handler) {
	    window.console.log('Example of how to override deregisterScrollHandler.');
	    window.removeEventListener('scroll', handler, false);
	};
	
	bubble.showIfAllowed();
    }, 1000);
}, false);

$(document).ready(function () {
    $('form#lookup_form').submit(function() {
        var inputData = { address: $('input#postal_code').val() };
	$('#submit_button').val($('#submit_button').attr('data-wait-value'));
	$('#submit_button').css('color', "#aaa");
	$('div#collection_times').hide();
	$.getJSON($('#lookup_form').attr('action'), inputData, function(data) {
	    $('#submit_button').val($('#submit_button').attr('data-active-value'));
	    $('#submit_button').css('color', "#000");
	    
	    if(data.status != 'SUCCESS') {
	            $('div#error').html('<p class="error">' + data.status + '</p>');
		return false;
	    }
	    $('div#error').empty();
	    
	    var latlng = data.geometry.location.lat + ',' + data.geometry.location.lng;
	    var mapHTML = '<img src=\"http://maps.google.com/maps/api/staticmap?center=' + latlng;
	    mapHTML += '&markers=' + latlng;
	    mapHTML += '&zoom=15&size=240x140&maptype=roadmap&sensor=false\"/>'
	    $('div#map').html(mapHTML);
	    
	    var pickupsHTML = '<table>';
	    for (var i in data.collections) {
		var pickup = data.collections[i];
		pickupsHTML += '<tr>';
		pickupsHTML += '<td valign=\"top\">' + '<img src=\"' + pickup['icon'] + '\"/>';
		pickupsHTML += '<br/><b>' + pickup['type'] + '</b></td>'
		pickupsHTML += '<td>' + pickup['desc'] + '</td>';
		pickupsHTML += '</tr>';
	    }
	    pickupsHTML += '</table>';
	    $('div#collection_times_content').html(pickupsHTML);
	    $('div#intro').hide();
	    $('div#collection_times').show();
	    $('span#search_term').html($('input#postal_code').val());
	    
	    var weekDate = new Date();
	    // if we're on saturday, get next week's schedule, otherwise get this week's
	    if (weekDate.getDay() === 6) {
		weekDate.setDate(weekDate.getDate()+1);
	    } else {
		weekDate.setDate(weekDate.getDate() - weekDate.getDay());
	    }
	    
	    $('span#search_week').html( weekDate.toLocaleDateString());
	    
	    $('div#collection_times').show();
	})
	    .error(function() { 
		$('div#error').html('<p class="error">Server error. Please try again later.</p>');
		return false; 
	    })
	    .complete(function() { 
		$('#anchor').focus();
		$('#submit_button').val($('#submit_button').attr('data-active-value'));
		$('#submit_button').css('color', "#000");
	    });
	
	return false;
    });
});
