# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class NetworkServerStats(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'bytes_sent': 'int',
        'bytes_received': 'int',
        'connections': 'int',
        'closed': 'int',
        'errors': 'int'
    }

    attribute_map = {
        'bytes_sent': 'bytes_sent',
        'bytes_received': 'bytes_received',
        'connections': 'connections',
        'closed': 'closed',
        'errors': 'errors'
    }

    def __init__(self, bytes_sent=None, bytes_received=None, connections=None, closed=None, errors=None):  # noqa: E501
        """NetworkServerStats - a model defined in Swagger"""  # noqa: E501

        self._bytes_sent = None
        self._bytes_received = None
        self._connections = None
        self._closed = None
        self._errors = None
        self.discriminator = None

        self.bytes_sent = bytes_sent
        self.bytes_received = bytes_received
        self.connections = connections
        self.closed = closed
        self.errors = errors

    @property
    def bytes_sent(self):
        """Gets the bytes_sent of this NetworkServerStats.  # noqa: E501

        The number of bytes written  # noqa: E501

        :return: The bytes_sent of this NetworkServerStats.  # noqa: E501
        :rtype: int
        """
        return self._bytes_sent

    @bytes_sent.setter
    def bytes_sent(self, bytes_sent):
        """Sets the bytes_sent of this NetworkServerStats.

        The number of bytes written  # noqa: E501

        :param bytes_sent: The bytes_sent of this NetworkServerStats.  # noqa: E501
        :type: int
        """
        self._bytes_sent = bytes_sent

    @property
    def bytes_received(self):
        """Gets the bytes_received of this NetworkServerStats.  # noqa: E501

        The number of bytes read  # noqa: E501

        :return: The bytes_received of this NetworkServerStats.  # noqa: E501
        :rtype: int
        """
        return self._bytes_received

    @bytes_received.setter
    def bytes_received(self, bytes_received):
        """Sets the bytes_received of this NetworkServerStats.

        The number of bytes read  # noqa: E501

        :param bytes_received: The bytes_received of this NetworkServerStats.  # noqa: E501
        :type: int
        """
        self._bytes_received = bytes_received

    @property
    def connections(self):
        """Gets the connections of this NetworkServerStats.  # noqa: E501

        The number of accepted client connections (the number of operations for UDP socket)  # noqa: E501

        :return: The connections of this NetworkServerStats.  # noqa: E501
        :rtype: int
        """
        return self._connections

    @connections.setter
    def connections(self, connections):
        """Sets the connections of this NetworkServerStats.

        The number of accepted client connections (the number of operations for UDP socket)  # noqa: E501

        :param connections: The connections of this NetworkServerStats.  # noqa: E501
        :type: int
        """
        self._connections = connections

    @property
    def closed(self):
        """Gets the closed of this NetworkServerStats.  # noqa: E501

        The number of closed client connections  # noqa: E501

        :return: The closed of this NetworkServerStats.  # noqa: E501
        :rtype: int
        """
        return self._closed

    @closed.setter
    def closed(self, closed):
        """Sets the closed of this NetworkServerStats.

        The number of closed client connections  # noqa: E501

        :param closed: The closed of this NetworkServerStats.  # noqa: E501
        :type: int
        """
        self._closed = closed

    @property
    def errors(self):
        """Gets the errors of this NetworkServerStats.  # noqa: E501

        The number of errors observed during connection  # noqa: E501

        :return: The errors of this NetworkServerStats.  # noqa: E501
        :rtype: int
        """
        return self._errors

    @errors.setter
    def errors(self, errors):
        """Sets the errors of this NetworkServerStats.

        The number of errors observed during connection  # noqa: E501

        :param errors: The errors of this NetworkServerStats.  # noqa: E501
        :type: int
        """
        self._errors = errors

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(NetworkServerStats, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, NetworkServerStats):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
