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


class TvlpStartConfiguration(object):
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
        'start_time': 'datetime',
        'cpu': 'TvlpStartSeriesConfiguration',
        'memory': 'TvlpStartSeriesConfiguration',
        'block': 'TvlpStartSeriesConfiguration',
        'packet': 'TvlpStartSeriesConfiguration',
        'network': 'TvlpStartSeriesConfiguration'
    }

    attribute_map = {
        'start_time': 'start_time',
        'cpu': 'cpu',
        'memory': 'memory',
        'block': 'block',
        'packet': 'packet',
        'network': 'network'
    }

    def __init__(self, start_time=None, cpu=None, memory=None, block=None, packet=None, network=None):  # noqa: E501
        """TvlpStartConfiguration - a model defined in Swagger"""  # noqa: E501

        self._start_time = None
        self._cpu = None
        self._memory = None
        self._block = None
        self._packet = None
        self._network = None
        self.discriminator = None

        if start_time is not None:
            self.start_time = start_time
        if cpu is not None:
            self.cpu = cpu
        if memory is not None:
            self.memory = memory
        if block is not None:
            self.block = block
        if packet is not None:
            self.packet = packet
        if network is not None:
            self.network = network

    @property
    def start_time(self):
        """Gets the start_time of this TvlpStartConfiguration.  # noqa: E501

        The ISO8601-formatted date and time to start profile replay. If not specified the profile will start immediately.   # noqa: E501

        :return: The start_time of this TvlpStartConfiguration.  # noqa: E501
        :rtype: datetime
        """
        return self._start_time

    @start_time.setter
    def start_time(self, start_time):
        """Sets the start_time of this TvlpStartConfiguration.

        The ISO8601-formatted date and time to start profile replay. If not specified the profile will start immediately.   # noqa: E501

        :param start_time: The start_time of this TvlpStartConfiguration.  # noqa: E501
        :type: datetime
        """
        self._start_time = start_time

    @property
    def cpu(self):
        """Gets the cpu of this TvlpStartConfiguration.  # noqa: E501


        :return: The cpu of this TvlpStartConfiguration.  # noqa: E501
        :rtype: TvlpStartSeriesConfiguration
        """
        return self._cpu

    @cpu.setter
    def cpu(self, cpu):
        """Sets the cpu of this TvlpStartConfiguration.


        :param cpu: The cpu of this TvlpStartConfiguration.  # noqa: E501
        :type: TvlpStartSeriesConfiguration
        """
        self._cpu = cpu

    @property
    def memory(self):
        """Gets the memory of this TvlpStartConfiguration.  # noqa: E501


        :return: The memory of this TvlpStartConfiguration.  # noqa: E501
        :rtype: TvlpStartSeriesConfiguration
        """
        return self._memory

    @memory.setter
    def memory(self, memory):
        """Sets the memory of this TvlpStartConfiguration.


        :param memory: The memory of this TvlpStartConfiguration.  # noqa: E501
        :type: TvlpStartSeriesConfiguration
        """
        self._memory = memory

    @property
    def block(self):
        """Gets the block of this TvlpStartConfiguration.  # noqa: E501


        :return: The block of this TvlpStartConfiguration.  # noqa: E501
        :rtype: TvlpStartSeriesConfiguration
        """
        return self._block

    @block.setter
    def block(self, block):
        """Sets the block of this TvlpStartConfiguration.


        :param block: The block of this TvlpStartConfiguration.  # noqa: E501
        :type: TvlpStartSeriesConfiguration
        """
        self._block = block

    @property
    def packet(self):
        """Gets the packet of this TvlpStartConfiguration.  # noqa: E501


        :return: The packet of this TvlpStartConfiguration.  # noqa: E501
        :rtype: TvlpStartSeriesConfiguration
        """
        return self._packet

    @packet.setter
    def packet(self, packet):
        """Sets the packet of this TvlpStartConfiguration.


        :param packet: The packet of this TvlpStartConfiguration.  # noqa: E501
        :type: TvlpStartSeriesConfiguration
        """
        self._packet = packet

    @property
    def network(self):
        """Gets the network of this TvlpStartConfiguration.  # noqa: E501


        :return: The network of this TvlpStartConfiguration.  # noqa: E501
        :rtype: TvlpStartSeriesConfiguration
        """
        return self._network

    @network.setter
    def network(self, network):
        """Sets the network of this TvlpStartConfiguration.


        :param network: The network of this TvlpStartConfiguration.  # noqa: E501
        :type: TvlpStartSeriesConfiguration
        """
        self._network = network

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
        if issubclass(TvlpStartConfiguration, dict):
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
        if not isinstance(other, TvlpStartConfiguration):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
