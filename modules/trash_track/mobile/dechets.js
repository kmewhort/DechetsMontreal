$(document).ready(function () {
        $('form#lookup_form').submit(function() {
            var inputData = { address: $('input#postal_code').val() };
	    $.getJSON('/json', inputData, function(data) {
	        if(data.status != 'SUCCESS') {
	            $('div#map').html('');
	            $('div#collection_times_content').html('<p class="address_error">' + data.status + '</p>');
	        }
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
	    });
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
	    

	    return false;
    });
});